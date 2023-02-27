#include <stdio.h>

typedef long long ll;

typedef struct IntPhi {
	int n;
	int phi;
} IP;

#define MOD (int)(1e9 + 7)
#define MAX_IDX 1000

int cmp(IP* a, IP* b) {
	return a->n > b->n;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		IP arr[MAX_IDX];
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			arr[i] = (IP){x, 0};
		}

		qsort(arr, n, sizeof(IP), cmp);
		arr[0].phi = 1;	 // phi(1)

		ll retval = 1;
		for (int i = 1; i < n; ++i) {
			int temp = 0;
			for (int j = 0; j < i; ++j) {
				if (arr[i].n % arr[j].n == 0) {
					temp += arr[j].phi;
				}
			}
			arr[i].phi = arr[i].n - temp;
			retval *= arr[i].phi, retval %= MOD;
		}

		printf("%lld\n", retval);
	}
	return 0;
}