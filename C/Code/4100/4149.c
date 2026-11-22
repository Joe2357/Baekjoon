#include <stdio.h>
#include <stdlib.h> // 랜덤 함수용
#include <time.h>	// 랜덤 함수용

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef unsigned long long ll;
typedef struct Node {
	ll num;
	int cnt;
} ND;

#define MAX_IDX 100000
ND prime[MAX_IDX];
int prime_len;

ll base[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
const int base_len = 12;

ll get_abs(ll x) {
	if (x < 0) {
		return -x;
	} else {
		return x;
	}
}

int asc(const void* a, const void* b) {
	if (((ND*)a)->num > ((ND*)b)->num) {
		return 1;
	} else if (((ND*)a)->num < ((ND*)b)->num) {
		return -1;
	} else {
		return 0;
	}
}

ll multiply_modular(ll a, ll k, ll n) {
	ll ret = 0;
	a %= n;

	while (k > 0) {
		if (k % 2 == 1) {
			ret = (ret + a) % n;
		}
		a = (a << 1) % n;
		k >>= 1;
	}
	return ret;
}

ll power_modular(ll a, ll k, ll n) {
	ll ret = 1;
	a %= n;

	while (k > 0) {
		if (k % 2 == 1) {
			// ret = ret * a % n;
			ret = multiply_modular(ret, a, n);
		}
		// a = (a * a) % n;
		a = multiply_modular(a, a, n);
		k >>= 1;
	}
	return ret;
}

bool miller_rabin(ll n, ll a) {
	ll k = n - 1;

	while (true) {
		ll m = power_modular(a, k, n);

		if (m == n - 1) {
			return true;
		} else if (k % 2 == 1) {
			return (m == 1 || m == n - 1);
		}
		k >>= 1;
	}
}

bool isPrime(ll x) {
	for (int i = 0; i < base_len; ++i) {
		if (base[i] % x == 0) {
			return true;
		} else if (x % base[i] == 0) {
			return false;
		}

		if (miller_rabin(x, base[i]) == false) {
			return false;
		}
	}
	return true;
}

ll get_gcd(ll a, ll b) {
	while (b > 0) {
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

/*
폴라드 로 알고리즘 (소수만 반환)
  - 입력 : 인수분해할 수 n
  - 출력 : n의 어떤 인수 (소수만 반환)
*/
ll pollard_rho_prime(ll n) {
	if (n % 2 == 0) { // 입력된 수가 짝수라면 2를 인수로 갖는다
		return 2;
	} else if (isPrime(n) == true) { // 입력된 수가 소수인지 확인
		return n;
	}

	// 변수 설정
	ll x = rand() % (n - 2) + 2;
	ll y = x;
	ll c = rand() % 10 + 1;
	ll g = 1;

	// 폴라드 로 알고리즘 수행
	while (g == 1) {
		/*
		x = (x * x % n + c) % n;
		y = (y * y % n + c) % n;
		y = (y * y % n + c) % n;
		g = get_gcd(get_abs(x - y), n);
		*/

		x = (multiply_modular(x, x, n) + c) % n;
		y = (multiply_modular(y, y, n) + c) % n;
		y = (multiply_modular(y, y, n) + c) % n;
		g = get_gcd(get_abs(x - y), n);

		if (g == n) { // 인수를 찾지 못했음
			return pollard_rho_prime(n);
		}
	}

	if (isPrime(g)) { // 찾은 인수가 소수라면 반환
		return g;
	} else { // 아니라면 찾은 g가 합성수이므로, g의 소인수를 찾기
		return pollard_rho_prime(g);
	}
}

void print_result() {
	// 소인수들을 오름차순 정렬
	qsort(prime, prime_len, sizeof(ND), asc);

	// 모든 소인수들에 대해 반복
	for (int i = 0; i < prime_len; ++i) {
		for (int j = 0; j < prime[i].cnt; ++j) {
			printf("%llu\n", prime[i].num);
		}
	}
	return;
}

int main() {
	srand(time(NULL)); // 랜덤 시드 설정

	ll num;
	scanf("%llu", &num);

	/* 알고리즘 시작 전 전처리 */
	/*
	for (int i = 0; i < base_len; ++i) {
		if (num % base[i] == 0) {
			int cnt = 0;
			while (num % base[i] == 0) {
				++cnt;
				num /= base[i];
			}

			prime[prime_len++] = (ND){base[i], cnt};
		}
	}*/

	while (num > 1) {
		ll factor = pollard_rho_prime(num); // 소인수 하나 찾음

		int cnt = 0;
		while (num % factor == 0) { // 소인수가 들어있는 개수 세기
			++cnt;
			num /= factor;
		}

		// 결과 배열에 입력
		prime[prime_len++] = (ND){factor, cnt};
	}

	print_result();
	return 0;
}