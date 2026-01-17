#include <stdio.h>

typedef struct CheckList {
	int i, j, k;
} CheckList;

#define MAX_IDX 100
#define MAX_TEST 1000
const int UNDEFINED = 2;
const int NORMAL = 1;
const int BROKEN = 0;

CheckList broken_list[MAX_TEST];
int broken_count = 0;

int pieces[MAX_IDX * 3 + 1];

int a, b, c;
int n;

void init() {
	for (int i = 0; i <= MAX_IDX * 3; ++i) {
		pieces[i] = UNDEFINED;
	}
	return;
}

int main() {
	init();
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &n);
	for (int t = 0; t < n; ++t) {
		int i, j, k, r;
		scanf("%d %d %d %d", &i, &j, &k, &r);
		if (r == NORMAL) {
			pieces[i] = NORMAL;
			pieces[j] = NORMAL;
			pieces[k] = NORMAL;
		} else {
			broken_list[broken_count++] = (CheckList){i, j, k};
		}
	}

	for (int i = 0; i < broken_count; ++i) {
		CheckList chk = broken_list[i];
		if (pieces[chk.i] == NORMAL && pieces[chk.j] == NORMAL) {
			pieces[chk.k] = BROKEN;
		} else if (pieces[chk.j] == NORMAL && pieces[chk.k] == NORMAL) {
			pieces[chk.i] = BROKEN;
		} else if (pieces[chk.k] == NORMAL && pieces[chk.i] == NORMAL) {
			pieces[chk.j] = BROKEN;
		}
	}

	for (int i = 1; i <= a + b + c; ++i) {
		printf("%d\n", pieces[i]);
	}
	return 0;
}