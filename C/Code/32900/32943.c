#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int NONE = 0;

typedef struct Log {
	int t;
	int s;
	int n;
} LOG;

#define MAX_IDX (int)(1e5 + 1)
LOG arr[MAX_IDX];
int seat[MAX_IDX + 1];
int user[MAX_IDX + 1];

int cmp(LOG* a, LOG* b) {
	return a->t > b->t;
}

void init(int x) {
	for (int i = 1; i <= x; ++i) {
		seat[i] = NONE;
		user[i] = NONE;
	}
	return;
}

int main() {
	int x, c, k;
	scanf("%d %d %d", &x, &c, &k);
	for (int i = 0; i < k; ++i) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		arr[i] = (LOG){t1, t2, t3};
	}
	qsort(arr, k, sizeof(LOG), cmp);

	init(c);
	for (int i = 0; i < k; ++i) {
		LOG current = arr[i];

		if (seat[current.s] == NONE) {
			seat[user[current.n]] = NONE;
			user[current.n] = current.s;
			seat[current.s] = current.n;
		}
	}

	for (int i = 1; i <= x; ++i) {
		if (user[i] != NONE) {
			printf("%d %d\n", i, user[i]);
		}
	}
	return 0;
}