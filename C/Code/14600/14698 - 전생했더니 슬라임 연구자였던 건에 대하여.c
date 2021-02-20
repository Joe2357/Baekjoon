#include <stdio.h>
#define MOD 1000000007

typedef long long LLD;
#define M_L 60
LLD heap[M_L + 2]; int len;

void push(LLD x) {
	heap[++len] = x;
	int i = len;

	while (i > 1) {
		if (heap[i] >= heap[i >> 1])
			break;
		heap[i] = heap[i >> 1], heap[i >> 1] = x;
		i >>= 1;
	}
	return;
}

LLD pop() {

	LLD retval = heap[1];
	heap[1] = heap[len--];
	int a = 1, b = 2;

	while (b <= len) {
		b += ((b != len) && (heap[b] > heap[b + 1]));
		if (heap[a] <= heap[b])
			break;
		LLD c = heap[b];
		heap[b] = heap[a], heap[a] = c;
		a = b, b <<= 1;
	}
	return retval;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		len = 0;
		for (int i = 0; i < n; ++i) {
			LLD a;
			scanf("%lld", &a);
			push(a);
		}

		LLD result = 1;

		while (len > 1) {
			LLD sum;
			push(sum = pop() * pop());
			result *= (sum % MOD), result %= MOD;
		}

		printf("%lld\n", result);
	}

	return 0;
}