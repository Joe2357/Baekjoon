#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_PICKS 3
#define MAX_IDX 5000
#define MAX_VAL (int)(1e5)

// canMake[i][j] = i개 숫자로 j-OFFSET 만들 수 있는지 여부
bool canMake[MAX_PICKS][MAX_VAL * (MAX_PICKS - 1) * 2 + 1];
const int OFFSET = MAX_VAL * (MAX_PICKS - 1);

int arr[MAX_IDX];
int n;

void init() {
	canMake[0][0 + OFFSET] = true; // 0은 0개로 만들 수 있음
	return;
}

int main() {
	init();
	scanf("%d", &n);

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);

		// 현재 수가 이전 수들 중 2개 + arr[j]로 만들 수 있는지 확인
		for (int j = 0; j < i; ++j) {
			if (canMake[2][arr[i] - arr[j] + OFFSET] == true) {
				ret += 1;
				break;
			}
		}

		// TODO : 시간초과 부분
		// arr[i]를 반드시 포함하는 경우를 추가하며 갱신
		canMake[1][arr[i] + OFFSET] = true; // arr[i] 하나로 만들 수 있음
		for (int j = 0; j <= i; ++j) {
			canMake[2][arr[i] + arr[j] + OFFSET] = true; // arr[i], arr[j] 두 개로 만들 수 있음
		}
	}

	printf("%d", ret);
	return 0;
}