#include <stdio.h>

#define MAX_IDX (int)(2e5)

typedef struct Problem {
	int deadline;
	int prize;
} Problem;

Problem problems[MAX_IDX];
int n;

int parent[MAX_IDX + 1];

int deadline_asc(const void* a, const void* b) {
	Problem* pa = (Problem*)a;
	Problem* pb = (Problem*)b;
	if (pa->deadline > pb->deadline) {
		return 1;
	} else if (pa->deadline < pb->deadline) {
		return -1;
	} else {
		return 0;
	}
}
int prize_desc(const void* a, const void* b) {
	Problem* pa = (Problem*)a;
	Problem* pb = (Problem*)b;
	if (pa->prize > pb->prize) {
		return -1;
	} else if (pa->prize < pb->prize) {
		return 1;
	} else {
		return deadline_asc(a, b);
	}
}

void init() {
	for (int i = 0; i <= MAX_IDX; ++i) {
		parent[i] = i;
	}
	return;
}

int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void union_set(int x, int y) {
	int a = find(x), b = find(y);
	parent[y] = parent[b] = a;
	return;
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &problems[i].deadline, &problems[i].prize);
	}
	return;
}

int main() {
	init();
	read_input();
	qsort(problems, n, sizeof(Problem), prize_desc);

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		Problem cur = problems[i];
		int available_day = find(cur.deadline);
		if (available_day > 0) {
			ret += cur.prize;
			union_set(available_day - 1, available_day);
		}
	}
	printf("%d", ret);
	return 0;
}