#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 15
const int EXIT_CODE = -1;
const int END_OF_LINE = 0;

int arr[MAX_IDX + 1];

void read_input() {
	for (int i = 0; i < MAX_IDX + 1; ++i) {
		scanf("%d", &arr[i]);

		// 입력 종료 조건
		if (arr[i] <= END_OF_LINE) {
			break;
		}
	}
	return;
}

int main() {
	while (true) {
		read_input();

		// 테스트케이스 종료 조건
		if (arr[0] == EXIT_CODE) {
			break;
		}

		int ret = 0;
		for (int i = 0; arr[i] > END_OF_LINE; ++i) {
			// 브루트포스 공략
			for (int j = 0; arr[j] > END_OF_LINE; ++j) {
				if (arr[i] * 2 == arr[j]) {
					ret += 1;
					break;
				}
			}
		}

		printf("%d\n", ret);
	}
	return 0;
}