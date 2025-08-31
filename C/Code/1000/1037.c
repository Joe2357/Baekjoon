#include <stdio.h>

#define MAX_IDX 50

int arr[MAX_IDX];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	return;
}

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	read_input(); // 입력에 1과 N이 없음

	// 그렇다면, 약수들 중 최솟값 x 최댓값 = N이 됨
	int min_value = arr[0];
	int max_value = arr[0];

	// 최솟값과 최댓값 찾기
	for (int i = 0; i < n; ++i) {
		min_value = min(min_value, arr[i]);
		max_value = max(max_value, arr[i]);
	}

	printf("%d", min_value * max_value);
	return 0;
}