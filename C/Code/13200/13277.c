#include <stdio.h>
#include <stdlib.h>

// -----------------------------------------------------------------------------
// 설정 및 자료구조
// -----------------------------------------------------------------------------
#define BASE 1000000000		// 10^9 (10억)
#define BASE_DIGITS 9		// 한 칸당 자릿수
#define KARATSUBA_CUTOFF 64 // 이 크기 미만은 일반 곱셈 사용 (튜닝 가능)

// 큰 정수 구조체
typedef struct {
	int* digits;  // Little Endian (digits[0]이 1의 자리 묶음)
	int len;	  // 현재 사용 중인 청크(chunk) 개수
	int capacity; // 할당된 청크 개수
	int sign;	  // 1: 양수, -1: 음수, 0: 0
} BigInt;

// 유틸리티 함수 선언
int bi_compare_abs(BigInt* a, BigInt* b);
BigInt* bi_add_abs(BigInt* a, BigInt* b);
BigInt* bi_sub_abs(BigInt* a, BigInt* b);
BigInt* bi_mul_karatsuba_abs(BigInt* a, BigInt* b);

// -----------------------------------------------------------------------------
// 1. 메모리 관리 및 기본 유틸리티
// -----------------------------------------------------------------------------

// 단순 max, min
int max_val(int a, int b) { return a > b ? a : b; }
int min_val(int a, int b) { return a < b ? a : b; }

// 문자열 길이
int my_strlen(const char* str) {
	int len = 0;
	while (str[len])
		len++;
	return len;
}

// 생성
BigInt* bi_new(int capacity) {
	if (capacity < 1)
		capacity = 1;
	BigInt* bi = (BigInt*)malloc(sizeof(BigInt));
	bi->digits = (int*)calloc(capacity, sizeof(int));
	bi->len = 1;
	bi->capacity = capacity;
	bi->sign = 0;
	return bi;
}

// 복제
BigInt* bi_copy(BigInt* src) {
	BigInt* dest = bi_new(src->len);
	dest->len = src->len;
	dest->sign = src->sign;
	for (int i = 0; i < src->len; i++)
		dest->digits[i] = src->digits[i];
	return dest;
}

// 부분 복제 (start 인덱스부터 len만큼)
BigInt* bi_slice(BigInt* src, int start, int len) {
	if (start >= src->len)
		return bi_new(1); // 0 반환
	int real_len = len;
	if (start + len > src->len)
		real_len = src->len - start;

	BigInt* dest = bi_new(real_len);
	dest->len = real_len;
	dest->sign = 1; // 기본 양수로 복사
	for (int i = 0; i < real_len; i++) {
		dest->digits[i] = src->digits[start + i];
	}
	return dest;
}

// 해제
void bi_delete(BigInt* bi) {
	if (bi) {
		if (bi->digits)
			free(bi->digits);
		free(bi);
	}
}

// 앞부분 0 제거
void bi_trim(BigInt* bi) {
	while (bi->len > 1 && bi->digits[bi->len - 1] == 0) {
		bi->len--;
	}
	if (bi->len == 1 && bi->digits[0] == 0)
		bi->sign = 0;
}

// 자릿수 시프트 (왼쪽으로 n칸 이동, 즉 * BASE^n)
BigInt* bi_shift(BigInt* src, int n) {
	if (n == 0)
		return bi_copy(src);

	BigInt* dest = bi_new(src->len + n);
	dest->len = src->len + n;
	dest->sign = src->sign; // 부호는 그대로

	// 앞쪽(낮은 자리)은 0으로 채워짐 (calloc 덕분)
	for (int i = 0; i < src->len; i++) {
		dest->digits[i + n] = src->digits[i];
	}
	return dest;
}

// 문자열 -> BigInt (Base 10^9 파싱)
BigInt* bi_from_string(const char* str) {
	int len = my_strlen(str);
	if (len == 0)
		return bi_new(1);

	int sign = 1;
	int start = 0;
	if (str[0] == '-') {
		sign = -1;
		start = 1;
	}

	int num_digits = len - start;
	int chunks = (num_digits + BASE_DIGITS - 1) / BASE_DIGITS;
	BigInt* bi = bi_new(chunks);
	bi->sign = sign;
	bi->len = chunks;

	int str_idx = len;
	int arr_idx = 0;
	while (str_idx > start) {
		int chunk_size = 0;
		int multiplier = 1;
		int value = 0;

		while (chunk_size < BASE_DIGITS && str_idx > start) {
			value += (str[str_idx - 1] - '0') * multiplier;
			multiplier *= 10;
			str_idx--;
			chunk_size++;
		}
		bi->digits[arr_idx++] = value;
	}
	bi_trim(bi);
	return bi;
}

// int -> BigInt
BigInt* bi_from_int(long long v) {
	BigInt* bi = bi_new(4);
	if (v == 0)
		return bi;

	if (v < 0) {
		bi->sign = -1;
		v = -v; // (LLONG_MIN은 여기선 고려하지 않음: 입력 범위에 따라 필요 시 수정)
	} else {
		bi->sign = 1;
	}

	bi->len = 0;
	while (v > 0) {
		bi->digits[bi->len++] = v % BASE;
		v /= BASE;
	}
	return bi;
}

// 출력
void bi_print(BigInt* bi) {
	if (bi->sign == 0) {
		printf("0");
		return;
	}
	if (bi->sign == -1)
		printf("-");
	printf("%d", bi->digits[bi->len - 1]);
	for (int i = bi->len - 2; i >= 0; i--) {
		printf("%09d", bi->digits[i]);
	}
}

// -----------------------------------------------------------------------------
// 2. 기본 연산 (절댓값 기준)
// -----------------------------------------------------------------------------

int bi_compare_abs(BigInt* a, BigInt* b) {
	if (a->len > b->len)
		return 1;
	if (a->len < b->len)
		return -1;
	for (int i = a->len - 1; i >= 0; i--) {
		if (a->digits[i] > b->digits[i])
			return 1;
		if (a->digits[i] < b->digits[i])
			return -1;
	}
	return 0;
}

BigInt* bi_add_abs(BigInt* a, BigInt* b) {
	int max_len = max_val(a->len, b->len) + 1;
	BigInt* res = bi_new(max_len);
	res->len = max_len;

	int carry = 0;
	for (int i = 0; i < max_len; i++) {
		long long sum = (long long)carry;
		if (i < a->len)
			sum += a->digits[i];
		if (i < b->len)
			sum += b->digits[i];

		if (sum >= BASE) {
			res->digits[i] = (int)(sum - BASE);
			carry = 1;
		} else {
			res->digits[i] = (int)sum;
			carry = 0;
		}
	}
	res->sign = 1; // 절댓값 연산 결과는 항상 비음수
	bi_trim(res);
	return res;
}

BigInt* bi_sub_abs(BigInt* a, BigInt* b) {
	// 전제: |a| >= |b|
	BigInt* res = bi_new(a->len);
	res->len = a->len;

	int borrow = 0;
	for (int i = 0; i < a->len; i++) {
		long long sub = (long long)a->digits[i] - borrow;
		if (i < b->len)
			sub -= b->digits[i];

		if (sub < 0) {
			sub += BASE;
			borrow = 1;
		} else {
			borrow = 0;
		}
		res->digits[i] = (int)sub;
	}
	res->sign = 1; // 절댓값 연산 결과는 항상 비음수
	bi_trim(res);
	return res;
}

// -----------------------------------------------------------------------------
// 3. 곱셈 (Karatsuba Algorithm)
// -----------------------------------------------------------------------------

// 일반 곱셈 (O(N^2)) - 작은 크기나 카라추바의 기저 사례용
BigInt* bi_mul_base(BigInt* a, BigInt* b) {
	// 부호를 이용한 조기 종료는 제거 (sign가 항상 정합하다고 보장되지 않기 때문)
	int len = a->len + b->len;
	BigInt* res = bi_new(len);
	res->len = len;

	for (int i = 0; i < a->len; i++) {
		long long carry = 0;
		for (int j = 0; j < b->len; j++) {
			long long cur = (long long)res->digits[i + j] + (long long)a->digits[i] * b->digits[j] + carry;
			res->digits[i + j] = (int)(cur % BASE);
			carry = cur / BASE;
		}
		// 남은 캐리 처리
		int k = i + b->len;
		while (carry > 0) {
			long long cur = (long long)res->digits[k] + carry;
			res->digits[k] = (int)(cur % BASE);
			carry = cur / BASE;
			k++;
		}
	}
	res->sign = 1; // 절대값 곱이므로 양수
	bi_trim(res);
	return res;
}

// 카라추바 곱셈 (절댓값 기준)
BigInt* bi_mul_karatsuba_abs(BigInt* a, BigInt* b) {
	int n = max_val(a->len, b->len);

	// 기저 조건: 크기가 작으면 일반 곱셈 수행
	if (n < KARATSUBA_CUTOFF) {
		return bi_mul_base(a, b);
	}

	int m = (n + 1) / 2; // 절반 지점

	// 쪼개기: x = x1 * B^m + x0
	BigInt* x0 = bi_slice(a, 0, m);
	BigInt* x1 = bi_slice(a, m, a->len - m);
	BigInt* y0 = bi_slice(b, 0, m);
	BigInt* y1 = bi_slice(b, m, b->len - m);

	// 재귀 호출
	// z2 = x1 * y1
	BigInt* z2 = bi_mul_karatsuba_abs(x1, y1);

	// z0 = x0 * y0
	BigInt* z0 = bi_mul_karatsuba_abs(x0, y0);

	// z1 구하기: (x1 + x0) * (y1 + y0) - z2 - z0
	BigInt* sum_x = bi_add_abs(x1, x0);
	BigInt* sum_y = bi_add_abs(y1, y0);
	BigInt* z1_raw = bi_mul_karatsuba_abs(sum_x, sum_y);

	// z1 = z1_raw - z2 - z0
	BigInt* temp = bi_sub_abs(z1_raw, z2);
	BigInt* z1 = bi_sub_abs(temp, z0);

	// 결과 조합: z2 * B^(2m) + z1 * B^m + z0
	BigInt* z2_shifted = bi_shift(z2, 2 * m);
	BigInt* z1_shifted = bi_shift(z1, m);

	BigInt* res_temp = bi_add_abs(z2_shifted, z1_shifted);
	BigInt* res = bi_add_abs(res_temp, z0);

	// 메모리 정리
	bi_delete(x0);
	bi_delete(x1);
	bi_delete(y0);
	bi_delete(y1);
	bi_delete(sum_x);
	bi_delete(sum_y);
	bi_delete(z1_raw);
	bi_delete(temp);
	bi_delete(z1);
	bi_delete(z2);
	bi_delete(z0);
	bi_delete(z2_shifted);
	bi_delete(z1_shifted);
	bi_delete(res_temp);

	return res;
}

// -----------------------------------------------------------------------------
// 4. 나눗셈 (Binary Search Division for Base 10^9)
// -----------------------------------------------------------------------------

// a * k (절댓값 기준)
BigInt* bi_mul_scalar(BigInt* a, int k) {
	if (k == 0)
		return bi_new(1);
	if (k == 1)
		return bi_copy(a);
	BigInt* res = bi_new(a->len + 1);
	res->len = a->len;
	long long carry = 0;
	for (int i = 0; i < a->len; i++) {
		long long cur = (long long)a->digits[i] * k + carry;
		res->digits[i] = (int)(cur % BASE);
		carry = cur / BASE;
	}
	if (carry > 0)
		res->digits[res->len++] = (int)carry;
	res->sign = 1;
	bi_trim(res);
	return res;
}

void bi_div_mod(BigInt* a, BigInt* b, BigInt** quotient, BigInt** remainder) {
	if (b->sign == 0) {
		printf("Error: Division by 0\n");
		exit(1);
	}

	// 부호 제외 절댓값 비교
	if (bi_compare_abs(a, b) < 0) {
		*quotient = bi_new(1);
		*remainder = bi_copy(a);
		return;
	}

	BigInt* q = bi_new(a->len);
	q->len = a->len; // 최대 길이로 설정 (나중에 trim)
	q->sign = 1;

	BigInt* r = bi_new(1); // Remainder (초기값 0)

	BigInt* b_abs = bi_copy(b);
	b_abs->sign = 1;

	// Long Division
	for (int i = a->len - 1; i >= 0; i--) {
		// r = r * BASE + a[i]
		BigInt* r_shifted = bi_shift(r, 1);
		r_shifted->digits[0] = a->digits[i];
		bi_trim(r_shifted);
		bi_delete(r);
		r = r_shifted;

		// r < b_abs 이면 몫은 0
		if (bi_compare_abs(r, b_abs) < 0) {
			q->digits[i] = 0;
			continue;
		}

		// 몫(q_digit) 찾기: 이진 탐색 (0 ~ BASE-1)
		int low = 0, high = BASE - 1;
		int ans = 0;

		while (low <= high) {
			int mid = (low + high) / 2;
			BigInt* bm = bi_mul_scalar(b_abs, mid);
			if (bi_compare_abs(bm, r) <= 0) { // bm <= r
				ans = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
			bi_delete(bm);
		}

		q->digits[i] = ans;

		// r = r - (b * ans)
		BigInt* sub_val = bi_mul_scalar(b_abs, ans);
		BigInt* new_r = bi_sub_abs(r, sub_val);
		bi_delete(r);
		bi_delete(sub_val);
		r = new_r;
	}

	bi_trim(q);
	q->sign = (a->sign == b->sign) ? 1 : -1;
	if (q->len == 1 && q->digits[0] == 0)
		q->sign = 0;

	r->sign = a->sign; // C언어 나머지 규칙 비슷하게
	if (r->len == 1 && r->digits[0] == 0)
		r->sign = 0;

	*quotient = q;
	*remainder = r;
	bi_delete(b_abs);
}

// -----------------------------------------------------------------------------
// 5. 공개 연산 인터페이스 (부호 처리)
// -----------------------------------------------------------------------------

// 전방 선언
BigInt* bi_sub(BigInt* a, BigInt* b);

BigInt* bi_add(BigInt* a, BigInt* b) {
	if (a->sign == 0)
		return bi_copy(b);
	if (b->sign == 0)
		return bi_copy(a);

	if (a->sign == b->sign) {
		BigInt* res = bi_add_abs(a, b);
		res->sign = a->sign;
		if (res->len == 1 && res->digits[0] == 0)
			res->sign = 0;
		return res;
	}

	// 부호 다름
	if (a->sign == 1) { // A > 0, B < 0
		BigInt* b_neg = bi_copy(b);
		b_neg->sign = 1;
		BigInt* res = bi_sub(a, b_neg);
		bi_delete(b_neg);
		return res;
	} else { // A < 0, B > 0
		BigInt* a_neg = bi_copy(a);
		a_neg->sign = 1;
		BigInt* res = bi_sub(b, a_neg);
		bi_delete(a_neg);
		return res;
	}
}

BigInt* bi_sub(BigInt* a, BigInt* b) {
	if (b->sign == 0)
		return bi_copy(a);
	if (a->sign == 0) {
		BigInt* res = bi_copy(b);
		res->sign = -res->sign;
		return res;
	}

	if (a->sign != b->sign) {
		BigInt* b_neg = bi_copy(b);
		b_neg->sign = a->sign;
		BigInt* res = bi_add_abs(a, b_neg);
		res->sign = a->sign;
		if (res->len == 1 && res->digits[0] == 0)
			res->sign = 0;
		bi_delete(b_neg);
		return res;
	}

	// 부호 같음
	int cmp = bi_compare_abs(a, b);
	if (cmp == 0)
		return bi_new(1); // 0

	if (cmp > 0) { // |A| > |B|
		BigInt* res = bi_sub_abs(a, b);
		res->sign = a->sign;
		return res;
	} else { // |B| > |A|
		BigInt* res = bi_sub_abs(b, a);
		res->sign = -a->sign;
		return res;
	}
}

BigInt* bi_mul(BigInt* a, BigInt* b) {
	if (a->sign == 0 || b->sign == 0)
		return bi_new(1);

	// 카라추바 호출 (절댓값 기준)
	BigInt* res = bi_mul_karatsuba_abs(a, b);
	res->sign = (a->sign == b->sign) ? 1 : -1;
	if (res->len == 1 && res->digits[0] == 0)
		res->sign = 0;
	return res;
}

BigInt* bi_div(BigInt* a, BigInt* b) {
	BigInt *q, *r;
	bi_div_mod(a, b, &q, &r);
	bi_delete(r);
	return q;
}

BigInt* bi_mod(BigInt* a, BigInt* b) {
	BigInt *q, *r;
	bi_div_mod(a, b, &q, &r);
	bi_delete(q);
	return r;
}

// -----------------------------------------------------------------------------
// 메인
// -----------------------------------------------------------------------------
int main() {
	char buf1[1000001];
	char buf2[1000001];

	if (!scanf("%1000000s", buf1))
		return 0;
	if (!scanf("%1000000s", buf2))
		return 0;

	BigInt* a = bi_from_string(buf1);
	BigInt* b = bi_from_string(buf2);

	BigInt* v_mul = bi_mul(a, b);
	bi_print(v_mul);

	// 메모리 정리
	bi_delete(a);
	bi_delete(b);
	bi_delete(v_mul);

	return 0;
}
