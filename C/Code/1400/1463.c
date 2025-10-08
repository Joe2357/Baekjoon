#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define MAX_INDEX 1000000

int dp[MAX_INDEX + 1] = {0, 0};
int n;

/* 1 ~ 100만의 dp값을 모두 기록해놓자 */
void init() {

	// i라는 수를 지금부터 만들어갈 것
	for (int i = 2; i <= MAX_INDEX; ++i) {
		int temp = dp[i - 1]; // +1을 할때의 연산

		if (i % 2 == 0) { // 추가적으로 /2 라는 연산을 할 수 있음
			temp = min(temp, dp[i / 2]);
		}
		if (i % 3 == 0) {
			temp = min(temp, dp[i / 3]);
		}
		dp[i] = ++temp; // 연산을 실행했음
	}

	return;
}

int main() {
	init();
	scanf("%d", &n);
	printf("%d", dp[n]);
	return 0;
}