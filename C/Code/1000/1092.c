#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CRANE 50
#define MAX_WEIGHT (int)(1e6)

int crane[MAX_CRANE];		 // 크레인이 들 수 있는 각 무게를 담은 배열
int freight[MAX_WEIGHT + 1]; // 각 무게의 화물이 몇개 있는가?
int n, m;

int max_weight = -1;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int desc(const void* a, const void* b) {
	int x = *(int*)a, y = *(int*)b;
	if (x > y) {
		return -1;
	} else if (x < y) {
		return 1;
	} else {
		return 0;
	}
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", crane + i);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		freight[x] += 1;
		max_weight = max(max_weight, x);
	}
	qsort(crane, n, sizeof(int), desc);
	return;
}

int main() {
	read_input();

	// 불가능한 경우 먼저 계산
	if (crane[0] < max_weight) {
		printf("-1");
		return 0;
	}

	int processed_cnt = 0, time;
	for (time = 0; processed_cnt < m; ++time) {
		for (int c = 0; c < n; ++c) { // 각 크레인에 대해서 계산
			while (crane[c] > 0) {
				if (freight[crane[c]] > 0) { // 화물이 있으면 처리
					freight[crane[c]] -= 1;
					processed_cnt += 1;
					break;
				} else { // 이 무게 이상은 더 이상 들 일이 없음
					crane[c] -= 1;
				}
			}
		}
	}
	printf("%d", time);
	return 0;
}