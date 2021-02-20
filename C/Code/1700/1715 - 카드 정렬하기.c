#include <stdio.h>

#define M_L (int)1e5
int heap[M_L + 2]; int len = 0;
long long result = 0;

void push(int x) {
	heap[++len] = x;
	for (int t = len; t > 1 && x < heap[t >> 1]; t >>= 1) {
		int a = heap[t >> 1];
		heap[t >> 1] = x, heap[t] = a;
	}
	return;
}

int pop() {
	int retval = heap[1];
	heap[1] = heap[len--];

	int a = 1, b = 2;
	while (b <= len) {
		b += ((b != len) & (heap[b] > heap[b + 1]));
		if (heap[a] <= heap[b]) {
			break;
		}
		else {
			int c = heap[a];
			heap[a] = heap[b];
			heap[b] = c;
		}
		a = b, b <<= 1;
	}

	return retval;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a;
		scanf("%d", &a);
		push(a);

		/*
		for (int i = 1; i <= len; ++i) {
			printf("%d ", heap[i]);
		}
		printf("\n");
		*/
	}

	while (len > 1) {
		int a = pop() + pop();
		// printf("t : %d\n", a);
		result += a;
		push(a);
	}

	printf("%lld", result);
	return 0;
}