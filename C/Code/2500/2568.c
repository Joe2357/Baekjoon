#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100000

typedef struct Line {
	int a, b;
} Line;

Line line[MAX_IDX];
int n;

int lis_path[MAX_IDX];
int pos[MAX_IDX];
int result[MAX_IDX];
bool is_included[MAX_IDX];

int a_asc(const void* a, const void* b) {
	Line* x = (Line*)a;
	Line* y = (Line*)b;

	if (x->a > y->a) {
		return 1;
	} else if (x->a < y->a) {
		return -1;
	} else {
		return 0;
	}
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &line[i].a, &line[i].b);
	}
	return;
}

int lower_bound(int target, int len) {
	int start = 0, end = len - 1;
	int res = len;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (lis_path[mid] >= target) {
			res = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return res;
}

void get_lis() {
	int len = 0;

	// nlogn lis 구하기
	for (int i = 0; i < n; ++i) {
		int target = line[i].b;
		int idx = lower_bound(target, len);

		lis_path[idx] = target;
		pos[i] = idx;

		if (idx == len) {
			len += 1;
		}
	}

	// lis가 설치해야하는 갯수이므로, 제거해야하는건 반대로 계산해야 함
	printf("%d\n", n - len);

	// 역추적 과정
	int find_idx = len - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (pos[i] == find_idx) {
			is_included[i] = true; // lis에 포함되는 원소
			find_idx -= 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (is_included[i] == false) {
			printf("%d\n", line[i].a);
		}
	}
	return;
}

int main() {
	read_input();
	qsort(line, n, sizeof(Line), a_asc);
	get_lis();
	return 0;
}