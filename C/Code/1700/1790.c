#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

ll n, k;

int main() {
	scanf("%lld %lld", &n, &k);

	ll write_len = 0;
	ll base = 10;
	bool isAnswered = false;

	for (ll digit = 1; digit <= 8; digit += 1, base *= 10) {
		ll count = base - base / 10;  // 현재 자릿수의 숫자 개수
		ll range_len = count * digit; // 현재 자릿수의 숫자들이 차지하는 전체 길이

		if (k > write_len + range_len) { // 이 자릿수로는 해결이 불가능
			write_len += range_len;
		} else {
			k -= write_len; // 이전 수들이 쓴 길이만큼 빼기
			isAnswered = true;

			/* 현재 길이의 숫자가 정답이 될 것 */
			k -= 1;
			ll index = k / digit + base / 10; // 현재 자릿수에서 몇 번째 숫자인지
			ll digit_index = k % digit;		  // 그 숫자에서 몇 번째 자릿수인지

			if (index > n) { // n보다 큰 수를 참조하는 경우
				printf("-1");
			} else {
				ll temp = index;
				for (int i = 0; i < digit - digit_index - 1; ++i) {
					temp /= 10;
				}
				printf("%lld", temp % 10);
			}
			break;
		}
	}

	if (isAnswered == false) {
		if (k > write_len + 9) { // 1억은 9자리 숫자이다
			printf("-1");
		} else {
			k -= write_len; // 이전 수들이 쓴 길이만큼 빼기
			ll digit = 9;
			ll digit_index = k - 1;
			ll temp = (ll)(1e8);
			for (int i = 0; i < digit - digit_index - 1; ++i) {
				temp /= 10;
			}
			printf("%lld", temp % 10);
		}
	}

	return 0;
}