#include <stdio.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_DIGITS 100
#define MORE_SPACE_FOR_INPUT 10
const int DIGIT = 10;

const int LEFT_BIGGER = 1;
const int RIGHT_BIGGER = -1;
const int EQUAL = 0;

const int KARATSUBA_THRESHOLD = 128; // Karatsuba 알고리즘 임계값

// ===== 구조체 정의 =====
typedef struct BigInteger {
	char digits[MAX_DIGITS + MORE_SPACE_FOR_INPUT]; // 각 자리 숫자 (digit[i] = 10^i 자리 숫자)
	int length;										// 숫자의 길이
	bool isNegative;								// 음수 여부
} BigInteger;

/* ===== 보조 함수 섹션 ===== */
void normalize(BigInteger* bi) {
	// 앞자리 0 제거
	while (bi->length > 1 && bi->digits[bi->length - 1] == 0) {
		bi->length--;
	}

	// 0만 남았다면 부호는 양수로 통일
	if (bi->length == 1 && bi->digits[0] == 0) {
		bi->isNegative = false;
	}
	return;
}

// 문자열을 BigInteger로 변환하는 함수
BigInteger createBigInteger(const char* str) {
	BigInteger bi;
	bi.length = 0;
	bi.isNegative = false;

	int start = 0;
	int len = strlen(str);

	// 부호 판별
	if (str[0] == '-') {
		bi.isNegative = true;
		start = 1;
	}

	// 뒤에서부터 역순 저장 (1의 자리 → 10의 자리)
	for (int i = len - 1; i >= start; --i) {
		if (str[i] >= '0' && str[i] <= '9') {
			bi.digits[bi.length++] = str[i] - '0';
		}
	}

	normalize(&bi);
	return bi;
}

// 큰 수의 절댓값을 더하여 반환
// 부호 판단 여부에는 관여하지 않음
BigInteger addAbsoluteValue(BigInteger a, BigInteger b) {
	BigInteger result;
	result.length = 0;
	result.isNegative = false;

	int carry = 0;
	int maxLen = (a.length > b.length ? a.length : b.length);

	for (int i = 0; i < maxLen || carry; ++i) {
		int sum = carry;
		if (i < a.length) {
			sum += a.digits[i];
		}
		if (i < b.length) {
			sum += b.digits[i];
		}

		result.digits[result.length++] = sum % DIGIT;
		carry = sum / DIGIT;
	}
	normalize(&result);
	return result;
}

// 절댓값이 큰 수에서 작은 수를 뺀 결과 반환
// 결과값은 항상 음이 아닌 정수 :: |a| >= |b| 이어야 함
BigInteger subtractAbsoluteValue(BigInteger a, BigInteger b) {
	BigInteger result;
	result.length = 0;
	result.isNegative = false;

	int borrow = 0;
	for (int i = 0; i < a.length; ++i) {
		int diff = a.digits[i] - borrow - (i < b.length ? b.digits[i] : 0);
		if (diff < 0) {
			diff += DIGIT;
			borrow = 1;
		} else {
			borrow = 0;
		}

		result.digits[result.length++] = diff;
	}

	normalize(&result);
	return result;
}

// 두 수의 절댓값을 비교하는 함수
// return [ LEFT_BIGGER = 1, RIGHT_BIGGER = -1, EQUAL = 0 ]
int compareAbsoluteValue(BigInteger a, BigInteger b) {
	if (a.length != b.length) {
		return (a.length > b.length) ? LEFT_BIGGER : RIGHT_BIGGER;
	}
	for (int i = a.length - 1; i >= 0; --i) {
		if (a.digits[i] != b.digits[i]) {
			return (a.digits[i] > b.digits[i]) ? LEFT_BIGGER : RIGHT_BIGGER;
		}
	}
	return EQUAL;
}

// m자리 수만큼 왼쪽으로 시프트 (10^m 곱셈 효과)
// a가 0일 경우 그대로 반환
BigInteger shiftLeft(BigInteger a, int m) {
	if (a.length == 1 && a.digits[0] == 0) {
		return a;
	}
	for (int i = a.length - 1; i >= 0; --i) {
		a.digits[i + m] = a.digits[i];
	}
	for (int i = 0; i < m; ++i) {
		a.digits[i] = 0;
	}
	a.length += m;
	return a;
}
/* ======================================== */

/* ===== 산술 연산 함수 섹션 ===== */
// 큰 수의 덧셈 함수
// 결과값 :: a + b
BigInteger add(BigInteger a, BigInteger b) {
	BigInteger result;

	if (a.isNegative == b.isNegative) {
		// 같은 부호 -> 절댓값 덧셈 후 부호 유지
		result = addAbsoluteValue(a, b);
		result.isNegative = a.isNegative;
	} else {
		// 부호 다름 -> 절댓값 비교 후 큰 쪽 - 작은 쪽
		int cmp = compareAbsoluteValue(a, b);
		if (cmp == EQUAL) {
			result = createBigInteger("0");
		} else if (cmp == LEFT_BIGGER) {
			result = subtractAbsoluteValue(a, b);
			result.isNegative = a.isNegative;
		} else { // cmp == RIGHT_BIGGER
			result = subtractAbsoluteValue(b, a);
			result.isNegative = b.isNegative;
		}
	}
	normalize(&result);
	return result;
}

// 큰 수의 뺄셈 함수
// 결과값 :: a - b
BigInteger subtract(BigInteger a, BigInteger b) {
	BigInteger result;

	if (a.isNegative == false && b.isNegative == false) { // (+a) - (+b)
		int cmp = compareAbsoluteValue(a, b);
		if (cmp == EQUAL) {
			result = createBigInteger("0");
		} else if (cmp == LEFT_BIGGER) {
			result = subtractAbsoluteValue(a, b);
			result.isNegative = false;
		} else { // RIGHT_BIGGER
			result = subtractAbsoluteValue(b, a);
			result.isNegative = true;
		}
	} else if (a.isNegative == false && b.isNegative == true) { // (+a) - (-b) = a + |b|
		result = addAbsoluteValue(a, b);
		result.isNegative = false;
	} else if (a.isNegative == true && b.isNegative == false) { // (-a) - (+b) = -( |a| + |b| )
		result = addAbsoluteValue(a, b);
		result.isNegative = true;
	} else { // (-a) - (-b) = b - a
		int cmp = compareAbsoluteValue(a, b);
		if (cmp == EQUAL) {
			result = createBigInteger("0");
		} else if (cmp == LEFT_BIGGER) {
			result = subtractAbsoluteValue(a, b);
			result.isNegative = true;
		} else { // RIGHT_BIGGER
			result = subtractAbsoluteValue(b, a);
			result.isNegative = false;
		}
	}
	normalize(&result);
	return result;
}

// 큰 수의 곱셈 함수 (짧은 숫자들의 곱셈)
// 결과값 :: a * b
BigInteger multiply_N2(BigInteger a, BigInteger b) {
	BigInteger result;
	memset(result.digits, 0, sizeof(result.digits));
	result.length = a.length + b.length;
	result.isNegative = (a.isNegative != b.isNegative);

	for (int i = 0; i < a.length; ++i) {
		int carry = 0;
		for (int j = 0; j < b.length || carry; ++j) {
			long long cur = result.digits[i + j] +
							(long long)a.digits[i] * (j < b.length ? b.digits[j] : 0) + carry;
			result.digits[i + j] = (char)(cur % DIGIT);
			carry = (int)(cur / DIGIT);
		}
	}
	normalize(&result);
	return result;
}

// 큰 수의 곱셈 함수 (Karatsuba 알고리즘)
// 결과값 :: a * b
// TODO :: 백준 13277번 시간초과 해결
BigInteger multiply(BigInteger a, BigInteger b) {
	normalize(&a);
	normalize(&b);

	int n = (a.length > b.length ? a.length : b.length);
	if (n <= KARATSUBA_THRESHOLD) { // 임계값 이하에서는 단순 곱셈
		return multiply_N2(a, b);
	}

	int m = n / 2;

	// low/high 분할
	BigInteger a_low, a_high, b_low, b_high;
	memset(&a_low, 0, sizeof(a_low));
	memset(&a_high, 0, sizeof(a_high));
	memset(&b_low, 0, sizeof(b_low));
	memset(&b_high, 0, sizeof(b_high));

	a_low.length = (a.length < m ? a.length : m);
	b_low.length = (b.length < m ? b.length : m);

	for (int i = 0; i < a_low.length; ++i) {
		a_low.digits[i] = a.digits[i];
	}
	for (int i = m; i < a.length; ++i) {
		a_high.digits[a_high.length++] = a.digits[i];
	}

	for (int i = 0; i < b_low.length; ++i) {
		b_low.digits[i] = b.digits[i];
	}
	for (int i = m; i < b.length; ++i) {
		b_high.digits[b_high.length++] = b.digits[i];
	}
	// 재귀 호출
	BigInteger z0 = multiply(a_low, b_low);
	BigInteger z2 = multiply(a_high, b_high);

	BigInteger a_sum = addAbsoluteValue(a_low, a_high);
	BigInteger b_sum = addAbsoluteValue(b_low, b_high);
	BigInteger z1 = multiply(a_sum, b_sum);
	z1 = subtract(z1, z0);
	z1 = subtract(z1, z2);

	// 결과 조합: z2 * 10^(2m) + z1 * 10^m + z0
	BigInteger res1 = shiftLeft(z2, 2 * m);
	BigInteger res2 = shiftLeft(z1, m);
	BigInteger result = add(add(res1, res2), z0);

	result.isNegative = (a.isNegative != b.isNegative);
	normalize(&result);
	return result;
}

// 큰 수의 나눗셈 함수 (몫)
// 결과값 :: a / b
BigInteger divide(BigInteger a, BigInteger b) {
	BigInteger quotient, remainder;
	memset(&quotient, 0, sizeof(quotient));
	memset(&remainder, 0, sizeof(remainder));
	quotient.length = 0;
	remainder.length = 1;
	remainder.digits[0] = 0;
	quotient.isNegative = (a.isNegative != b.isNegative);
	remainder.isNegative = false;

	// 0 나눗셈 방지
	if (b.length == 1 && b.digits[0] == 0) {
		printf("[Error] Division by zero\n");
		return createBigInteger("0");
	}

	// 절댓값만으로 연산
	a.isNegative = false;
	b.isNegative = false;

	// 나눗셈 본체 (상위 자리부터)
	for (int i = a.length - 1; i >= 0; --i) {
		// remainder = remainder * 10 + a.digits[i]
		if (remainder.length != 1 || remainder.digits[0] != 0) {
			remainder = shiftLeft(remainder, 1);
		}
		remainder.digits[0] = a.digits[i];
		if (remainder.length == 1 && remainder.digits[0] == 0) {
			remainder.length = 1;
		} else {
			normalize(&remainder);
		}

		// q_digit = remainder / b (0~9 사이)
		int q_digit = 0;
		while (compareAbsoluteValue(remainder, b) != RIGHT_BIGGER) {
			remainder = subtractAbsoluteValue(remainder, b);
			q_digit++;
		}
		quotient.digits[i] = q_digit;
	}

	// quotient의 길이 계산
	quotient.length = a.length;
	normalize(&quotient);

	return quotient;
}

// 큰 수의 나눗셈 함수 (나머지)
// 결과값 :: a % b
BigInteger modular(BigInteger a, BigInteger b) {
	BigInteger q = divide(a, b);
	BigInteger qb = multiply(q, b);
	BigInteger r = subtract(a, qb); // r = a - q*b

	// 나머지값 보정
	BigInteger babs = b;
	babs.isNegative = false;
	if (r.isNegative == true) {
		r = add(r, babs);
	}
	while (compareAbsoluteValue(r, babs) != RIGHT_BIGGER) {
		r = subtractAbsoluteValue(r, babs);
	}
	return r;
}

// 큰 수의 거듭제곱 함수 (빠른 제곱법)
// 결과값 :: base ^ exp (exp는 0 이상의 정수)
BigInteger power(BigInteger base, int exp) {
	BigInteger result = createBigInteger("1");

	bool resultNegative = false;
	if (base.isNegative == true && (exp % 2 == 1)) {
		resultNegative = true;
	}
	base.isNegative = false;

	while (exp > 0) {
		if (exp % 2 == 1) {
			result = multiply(result, base);
		}
		base = multiply(base, base);
		exp /= 2;
	}

	result.isNegative = resultNegative;
	normalize(&result);
	return result;
}
/* ======================================== */

/* ===== 출력 함수 섹션 ===== */
// BigInteger 출력 함수
void printBigInteger(BigInteger a) {
	if (a.isNegative == true && (a.length > 1 || a.digits[0] != 0)) {
		printf("-");
	}
	for (int i = a.length - 1; i >= 0; --i) {
		printf("%d", a.digits[i]);
	}
	return;
}
/* ======================================== */

int main() {
	char n[MAX_DIGITS + MORE_SPACE_FOR_INPUT + 1], m[MAX_DIGITS + MORE_SPACE_FOR_INPUT + 1];
	scanf("%s %s", n, m);

	BigInteger bigN = createBigInteger(n);
	BigInteger bigM = createBigInteger(m);

	BigInteger temp = subtract(bigN, bigM);
	BigInteger fair_share = divide(temp, createBigInteger("2"));
	printBigInteger(add(bigM, fair_share));
	printf("\n");
	printBigInteger(fair_share);
	return 0;
}