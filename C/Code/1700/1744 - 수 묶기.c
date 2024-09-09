#include <stdio.h>

#define MAX_IDX 50

int pos[MAX_IDX], pos_len;
int neg[MAX_IDX], neg_len;
int n;

#define abs(x) (((x) > 0) ? (x) : (-(x)))

int cmp(int* a, int* b) { return abs(*a) > abs(*b); }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (a > 0) {
			pos[pos_len++] = a;
		} else {
			neg[neg_len++] = a;
		}
	}

	qsort(pos, pos_len, sizeof(int), cmp);
	qsort(neg, neg_len, sizeof(int), cmp);

	int retval = 0;

	/* solve() */
	while (pos_len > 1) {
		int a = pos[--pos_len];
		int b = pos[--pos_len];
		if (a * b > a + b) {
			retval += (a * b);
		} else {
			retval += (a + b);
		}
	}
	if (pos_len > 0) {
		retval += pos[0];
	}

	while (neg_len > 1) {
		int a = neg[--neg_len];
		int b = neg[--neg_len];

		retval += (a * b);
	}
	if (neg_len > 0) {
		retval += neg[0];
	}

	printf("%d", retval);
	return 0;
}