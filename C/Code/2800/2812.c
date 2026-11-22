#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct HeapNode {
	char val;
	int idx;
} HN;

#define MAX_IDX (int)(5e5 + 1)
const int HEAD = 1;

char str[MAX_IDX];
char ans[MAX_IDX];
int len_ans;
int n, k;

HN h[MAX_IDX * 4 + 10]; // max heap
int top = 0;

bool isFront(HN a, HN b) {
	// 1. value는 더 커야한다
	// 2. value가 같다면 index는 작아야 한다
	return ((a.val > b.val) || ((a.val == b.val) && (a.idx < b.idx)));
}

bool isHeapEmpty() {
	return (top == 0);
}

void insertHeap(HN x) {
	int i;
	for (i = ++top; (i > 1) && (isFront(x, h[i / 2]) == true); i /= 2) {
		h[i] = h[i / 2];
	}
	h[i] = x;
	return;
}

int popHeap() {
	HN retval = h[HEAD], temp = h[top--];
	int parent = 1, child = 2;

	while (child <= top) {
		if ((child < top) && (isFront(h[child + 1], h[child]) == true)) {
			child += 1;
		}
		if (isFront(temp, h[child]) == true) {
			break;
		}

		h[parent] = h[child];
		parent = child, child *= 2;
	}
	h[parent] = temp;
	return retval.idx;
}

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", str);

	int last_selected = -1;
    int last_inserted = -1;

	while (k > 0) {
		while ((isHeapEmpty() == false) && (h[HEAD].idx <= last_selected)) {
			int temp = popHeap();
		}
		for (int i = last_inserted + 1; i <= last_selected + k + 1; ++i) {
			insertHeap((HN){str[i], i});
		}
        last_inserted = last_selected + k + 1;

		int cur = popHeap();
		ans[len_ans++] = str[cur];
		k -= (cur - last_selected - 1);
		last_selected = cur;

		if (last_selected + k + 1 >= n) {
			break;
		}
	}

	for (int i = last_selected + k + 1; i < n; ++i) {
		ans[len_ans++] = str[i];
	}
	ans[len_ans++] = '\0';

	printf("%s", ans);
	return 0;
}