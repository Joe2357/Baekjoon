#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	int idx;
} Node;

#define MAX_IDX (int)(5e5)

Node arr[MAX_IDX];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].val);
		arr[i].idx = i;
	}
	return;
}

int val_asc(const void* a, const void* b) {
	Node* na = (Node*)a;
	Node* nb = (Node*)b;

	if (na->val != nb->val) {
		return na->val - nb->val;
	} else {
		return na->idx - nb->idx;
	}
}

int main() {
	read_input();
	qsort(arr, n, sizeof(Node), val_asc);

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		int diff = (arr[i].idx - i);
		ret = max(ret, diff);
	}
	printf("%d", ret + 1);
	return 0;
}