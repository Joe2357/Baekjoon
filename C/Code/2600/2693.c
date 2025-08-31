#include <stdio.h>

// 상수는 고정됨
#define MAX_IDX 10
const int N = 3;

int arr[MAX_IDX];

int desc(int* a, int* b) {
	return *a < *b;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		for (int i = 0; i < MAX_IDX; ++i) {
			scanf("%d", &arr[i]);
		}

		// 정렬 진행 (내림차순)
		qsort(arr, MAX_IDX, sizeof(int), desc);

		// N번째 큰 수를 출력
		printf("%d\n", arr[N - 1]);
	}
	return 0;
}