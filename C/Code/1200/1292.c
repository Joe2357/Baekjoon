#include <stdio.h>

#define MAX_IDX 1000

int arr[MAX_IDX];

// 배열 미리 만드는 함수
void init() {
	int idx = 0;

	for (int i = 1; idx < MAX_IDX; ++i) {
		for (int j = 0; j < i && idx < MAX_IDX; ++j) {
			arr[idx++] = i;
		}
	}
	return;
}

int main() {
	init();

	int a, b;
	scanf("%d %d", &a, &b);

	int ret = 0;
	for (int i = a - 1; i < b; ++i) { // 구간합
		ret += arr[i];
	}
	printf("%d", ret);
	return 0;
}