#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 9999

typedef struct Heap {
	int v[MAX_IDX + 2];
	int len;
} Heap;

Heap lower, upper;
int current_median;

void init() {
	lower.len = 0;
	upper.len = 0;
	return;
}

int get_length(Heap* h) {
	return h->len;
}

void lower_push(int x) {
	int idx = ++lower.len;
	while (idx > 1 && x > lower.v[idx / 2]) {
		lower.v[idx] = lower.v[idx / 2];
		idx /= 2;
	}
	lower.v[idx] = x;
	return;
}

int lower_pop() {
	int res = lower.v[1];
	int last = lower.v[lower.len--];
	int parent = 1, child = 2;
	while (child <= lower.len) {
		child += (child < lower.len && lower.v[child] < lower.v[child + 1]);
		if (last >= lower.v[child]) {
			break;
		}
		lower.v[parent] = lower.v[child];
		parent = child;
		child *= 2;
	}
	lower.v[parent] = last;
	return res;
}

void upper_push(int x) {
	int idx = ++upper.len;
	while (idx > 1 && x < upper.v[idx / 2]) {
		upper.v[idx] = upper.v[idx / 2];
		idx /= 2;
	}
	upper.v[idx] = x;
	return;
}

int upper_pop() {
	int res = upper.v[1];
	int last = upper.v[upper.len--];
	int parent = 1, child = 2;
	while (child <= upper.len) {
		child += (child < upper.len && upper.v[child] > upper.v[child + 1]);
		if (last <= upper.v[child]) {
			break;
		}
		upper.v[parent] = upper.v[child];
		parent = child;
		child *= 2;
	}
	upper.v[parent] = last;
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		int n;
		scanf("%d %d", &n, &current_median);
		printf("%d\n%d", (n + 1) / 2, current_median);

		int printed_cnt = 1;
		for (int i = 1; i < n; i += 2) {
			int a, b;
			scanf("%d %d", &a, &b);

			if (a < current_median) {
				lower_push(a);
			} else {
				upper_push(a);
			}
			if (b < current_median) {
				lower_push(b);
			} else {
				upper_push(b);
			}

			if (get_length(&lower) > get_length(&upper)) {
				upper_push(current_median);
				current_median = lower_pop();
			} else if (get_length(&lower) < get_length(&upper)) {
				lower_push(current_median);
				current_median = upper_pop();
			} else {
			}

			if (printed_cnt % 10 == 0) {
				printf("\n");
			} else {
				printf(" ");
			}
			printf("%d", current_median);
			printed_cnt += 1;
		}
		printf("\n");
	}
	return 0;
}