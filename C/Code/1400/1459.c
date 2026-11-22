#include <stdio.h>

typedef long long ll;

ll x, y, w, s;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	scanf("%lld %lld %lld %lld", &x, &y, &w, &s);
	ll ret = 0LL;

	if (2 * w <= s) { // 대각선으로 갈 필요가 없는 경우
		ret = w * (x + y);
	} else if (w > s) { // 대각선이 직선보다도 더 효율적인 경우
						// 이 경우, 직선 2번 이동보다 대각선 2번 이동이 더 빠름
		ll temp = min(x, y);
		ret += (s * temp);
		x -= temp, y -= temp;

		ret += (2 * s * (x / 2));
		ret += (2 * s * (y / 2));

		// 남은 위치 계산
		int c = (x % 2 + y % 2);
		if (c == 2) { // 대각선 이동
			ret += s;
		} else if (c == 1) { // 직선 이동
			ret += w;
		}

	} else { // 직선과 대각선을 적절히 사용해야함
		ll temp = min(x, y);
		ret += (s * temp);
		ret += (w * (max(x, y) - temp));
	}

	printf("%lld", ret);
	return 0;
}