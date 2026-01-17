#include <stdio.h>

#define MAX_IDX (int)(1e5)
const int DIGIT = 10;

int a[MAX_IDX];
int b[MAX_IDX];

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}

	long long current_adrenaline = 0LL;
	for (int i = 0; i < n; ++i) {
		int t1, t2;
		scanf("%d.%d", &t1, &t2);
		current_adrenaline += max(a[i] * (t1 * DIGIT + t2) / DIGIT - b[i], -b[i] * (t1 * DIGIT + t2) / DIGIT + a[i]);
	}
	printf("%lld", current_adrenaline);
	return 0;
}