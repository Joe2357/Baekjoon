#include <stdio.h>

#define MAX_LEN (int)1e6

typedef struct Node {
	long long a, b, c;
} ND;

ND arr[2 + MAX_LEN + 2];
int n;
long long result = 0;

#define min(a, b) (((a) > (b)) ? (b) : (a))
int main() {
	long long COST_B, COST_C;
	scanf("%d %lld %lld", &n, &COST_B, &COST_C);
	arr[0] = arr[1] = (ND) { 0 };
	for (int i = 2; i < n + 2; ++i) {
		arr[i] = (ND) { 0, 0, 0 };

		int t;
		scanf("%d", &t);

		if (COST_B <= COST_C) {
			result += (t * COST_B);
		}
		else {
			int b = min(arr[i - 1].a, t);
			result += (b * COST_C);
			arr[i].b += b, arr[i - 1].a -= b, t -= b;

			int c = min(arr[i - 1].b, t);
			result += (c * COST_C);
			arr[i].c += c, arr[i - 1].b -= c, t -= c;

			arr[i].a += t;
			result += (t * COST_B);
		}
	}

	printf("%lld", result);
	return 0;
}