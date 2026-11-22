#include <stdio.h>

#define MAX_IDX 1500

typedef struct {
	int heap[MAX_IDX + 1];
	int size;
} MinHeap;

void push(MinHeap* h, int value) {
	h->size += 1;
	int i = h->size;
	while (i > 1 && value < h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = value;
	return;
}

int pop(MinHeap* h) {
	int root = h->heap[1];
	int last = h->heap[h->size--];
	int parent = 1, child = 2;

	while (child <= h->size) {
		child += (child < h->size && h->heap[child] > h->heap[child + 1]);
		if (last <= h->heap[child]) {
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = last;
	return root;
}

int main() {
	MinHeap h;
	h.size = 0;
	int n, temp;

	scanf("%d", &n);
	for (int i = 0; i < n * n; ++i) {
		scanf("%d", &temp);
		if (h.size < n) {
			push(&h, temp);
		} else {
			// 현재 힙의 최솟값보다 큰 놈이 들어오면 교체
			if (temp > h.heap[1]) {
				pop(&h);		// 제일 작은 놈 퇴출
				push(&h, temp); // 새 강자 영입
			}
		}
	}

	printf("%d", h.heap[1]);
	return 0;
}