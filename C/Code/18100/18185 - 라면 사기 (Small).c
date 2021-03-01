#include <stdio.h>

#define COST_A 3
#define COST_B 2
#define COST_C 2
#define MAX_LEN (int)1e4

typedef struct Node {
	int a, b, c;
} ND;

ND arr[2 + MAX_LEN + 2];
int n, result = 0;

#define min(a, b) (((a) > (b)) ? (b) : (a))
int main() {
	scanf("%d", &n);
	arr[0] = arr[1] = (ND) { 0 };
	for (int i = 2; i < n + 2; ++i) {
		arr[i] = (ND) { 0, 0, 0 };

		int t;
		scanf("%d", &t);

		int b = min(arr[i - 1].a, t);
		result += (b * COST_C);
		arr[i].b += b, arr[i - 1].a -= b, t -= b;

		int c = min(arr[i - 1].b, t);
		result += (c * COST_C);
		arr[i].c += c, arr[i - 1].b -= c, t -= c;

		arr[i].a += t;
		result += (t * COST_A);
	}

	printf("%d", result);
	return 0;
}