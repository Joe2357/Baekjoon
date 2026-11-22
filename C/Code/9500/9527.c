#include <stdio.h>

typedef long long ll;

ll a, b;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
 * 1부터 x까지, 이진수로 나타내었을 때 1의 개수를 세는 함수
 * @param x 상한 값
 * @return 1의 개수 합
 */
ll solve(ll x) {
	if (x <= 0LL) {
		return 0LL;
	}
	ll ret = 0LL;

	// i번째 비트에 대해 계산
	for (ll i = 1LL; i <= x; i <<= 1LL) {
		ll step = (i << 1LL); // 2^(i+1)
		ll full = (x / step); // 완전한 그룹의 개수
		ret += (full * i);	  // 완전한 그룹에서의 1의 개수

		ll rem = (x % step);			// 나머지
		ret += max(0LL, rem - i + 1LL); // 나머지에서의 1의 개수
	}

	return ret;
}

int main() {
	scanf("%lld %lld", &a, &b);
	printf("%lld", solve(b) - solve(a - 1));
	return 0;
}