#include <stdio.h>

#define MAX_IDX 100000

int num[MAX_IDX];
int need[MAX_IDX];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &need[i]);
	}
	return;
}

int main() {
	read_input();

	for (int i = 0; i < n; ++i) {
		int ret = 0;

		if (need[i] == 0) { // 살게 없는 경우
			ret = 0;
		} else if (num[i] == 1) { // 한 묶음만 사면 무제한으로 얻을 수 있음
			ret = 1;
		} else if (num[i] >= need[i]) {
			ret = need[i];
		} else if (num[i] + 1 == need[i]) { // 한 묶음만 사면 얻을 수 있음
			ret = num[i];
		} else {
			int quotient = 0;
			if (need[i] % num[i] == 0) {
				quotient = (need[i] / num[i]) - 1;
			} else {
				quotient = need[i] / num[i];
			}

			need[i] -= (quotient * num[i] + 1);
			ret = quotient * (num[i] - 1) + 1 + need[i];
		}

		printf("%d ", ret);
	}
	return 0;
}