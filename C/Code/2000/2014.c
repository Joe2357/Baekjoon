#include <stdio.h>

typedef struct Node {
	int value;
	int last_picked_prime_index;
} ND;

#define HEAP_MAX_LEN (int)(1e5)
#define ARR_MAX_IDX 100
const long long MAX_VAL = ((long long)1 << 31);
const int HEAD = 1;

ND heap[ARR_MAX_IDX * HEAP_MAX_LEN + 10];
int top;

long long arr[ARR_MAX_IDX];

void insert(int x, int last_picked_idx) {
	heap[++top] = (ND){x, last_picked_idx};
	int i = top;

	while (i > HEAD) {
		if (heap[i].value >= heap[i >> 1].value) {
			break;
		} else {
			ND temp = heap[i];
			heap[i] = heap[i >> 1];
			heap[i >> 1] = temp;
			i >>= 1;
		}
	}
	return;
}

ND pop() {
	ND ret = heap[HEAD];
	heap[HEAD] = heap[top--];
	int i = HEAD, ii = (HEAD << 1);

	while (ii < top) {
		if (heap[ii].value > heap[ii + 1].value) {
			++ii;
		}

		if (heap[i].value <= heap[ii].value) {
			break;
		} else {
			ND temp = heap[ii];
			heap[ii] = heap[i];
			heap[i] = temp;

			i = ii, ii <<= 1;
		}
	}
	if (ii == top) {
		if (heap[i].value > heap[ii].value) {
			ND temp = heap[ii];
			heap[ii] = heap[i];
			heap[i] = temp;
		}
	}

	return ret;
}

int main() {
	int k, n;
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; ++i) {
		scanf("%lld", arr + i);
		insert((int)arr[i], i);
	}

	ND ret = (ND){0, 0};
	while (n--) {
		ret = pop();
		if (ret.value == 0) {
			break;
		}
		for (int i = ret.last_picked_prime_index; i < k; ++i) {
			long long temp = arr[i] * ret.value;

			if (temp < MAX_VAL) { // overflow check
				insert(ret.value * arr[i], i);
			}
		}
	}

	printf("%d", ret.value);
	return 0;
}