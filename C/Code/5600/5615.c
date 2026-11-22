#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef unsigned long long ll;

/* 제곱 함수
  - 입력값 : base a, 제곱 횟수 k, 모듈러 base n
  - 출력값 : (a^k) % n
*/
ll power_modular(ll a, ll k, ll n) {
	ll ret = 1;
	a %= n; // 미리 모듈러 진행

	// 분할정복 제곱방식
	while (k > 0) {
		if (k % 2 == 1) {
			ret = ret * a % n;
		}

		k >>= 1; // 제곱 횟수를 1/2배하는 것으로 시간복잡도 해소
		a = (a * a) % n;
	}

	return ret;
}

/* 밀러-라빈 소수판별법 수행 함수
  - 입력값 :: 검사할 수 n, base 수 a
  - 반환값 :: 합성수가 아님 여부 (true / false)
*/
bool miller_rabin(ll n, ll a) {
	ll k = n - 1; // a^k = a^{d * 2^s} 로 표기 가능

	while (true) {					   // 큰수부터 아래로 내려가기
		ll m = power_modular(a, k, n); // a^k 계산
		if (m == n - 1) {			   // a^k = -1 (mod n) 를 만족하는 k는 존재하기만 하면 됨
			return true;
		}
		if (k % 2 == 1) { // 마지막 k (s=0인 경우). 이 때에는 a^k = 1 or -1 (mod n)이어야 소수
			return (m == 1 || m == n - 1);
		}
		k >>= 1; // (d * 2^s) => (d * 2^(s-1)) 변환
	}
}

/* 소수 체크 함수
  - 입력값 : 소수 판별할 값 x
  - 출력값 : 소수 여부 (true / false)
*/
bool isPrime(ll x) {
	bool ret = true;
	ll base[3] = {2, 7, 61}; // unsigned int에서는 이 3개의 소수만 확인해도 충분하다.
	const int BASE_LEN = 3;

	for (int i = 0; i < BASE_LEN; ++i) {
		if (x == base[i]) { // 1. base는 소수만 존재한다.
			return true;
		} else if (x % base[i] == 0) { // 2. base와 같지 않으면서 나눠질 수 있다면 합성수다.
			return false;
		}

		// 3. 밀러-라빈 검사 결과 병합
		ret &= miller_rabin(x, base[i]);
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);

	int ret = 0;
	while (n--) {
		ll area;
		scanf("%lld", &area);

		/*
		2xy + x + y = k
		4xy + 2x + 2y = 2k
		2x(2y + 1) + 2y = 2k
		2x(2y + 1) + (2y + 1) = 2k + 1
		(2y + 1)(2x + 1) = 2k + 1
		즉, 입력된 값 k에 대해 2k+1은 두 홀수의 곱으로 나타난다.
		(x, y가 양의 정수이므로, 1이 아닌 홀수의 곱들로 표현된다)
		=> 2k + 1은 "합성수"여야만 한다
		*/
		if (isPrime(2 * area + 1) == true) {
			++ret;
		}
	}

	printf("%d", ret);
	return 0;
}
