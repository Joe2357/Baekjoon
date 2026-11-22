#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

#define MAX_IDX (int)(1e5)

ull arr[MAX_IDX];
int n;

#define min(a, b) (((a) > (b)) ? (b) : (a))

int asc(const void* a, const void* b) {
	ull* x = (ull*)a;
	ull* y = (ull*)b;

	if (*x > *y) {
		return 1;
	} else if (*x < *y) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	ull m, sum = 0ULL;
	int n;
	scanf("%llu %d", &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%llu", arr + i);
		sum += arr[i];
	}
	qsort(arr, n, sizeof(ull), asc); // 작은 순부터 처리
	ull need = sum - m;				 // 부족한 사탕 갯수

	ull ret = 0ULL;
	for (int i = 0; i < n; ++i) {
		ull need_avg = need / (n - i); // 남은 인원이 얻지 못하는 사탕의 평균 갯수
		ull tmp = min(need_avg, arr[i]);

		ret += (tmp * tmp); // 이만큼 분노가 쌓임
		need -= tmp;		// 이만큼 제외해야 함
	}
	printf("%llu", ret);
	return 0;
}