#include <stdio.h>

#define MAX_IDX 90

long long fibonacci[MAX_IDX + 1] = {0, 1}; // 초기값 설정

int main() {
	int n;
	scanf("%d", &n);

	// 반복을 통해 피보나치 수 계산
	for (int i = 2; i <= n; ++i) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	// 결과 출력
	printf("%lld", fibonacci[n]);
	return 0;
}