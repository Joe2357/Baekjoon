#include <stdio.h>

#define MAX_IDX (int)(1e5)

int arr[MAX_IDX];
int n;

int get_gcd(int a, int b) {
	while (b > 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	int gcd = arr[1] - arr[0];
	for (int i = 2; i < n; ++i) {
		gcd = get_gcd(gcd, arr[i] - arr[i - 1]);
	}

	printf("%d", (arr[n - 1] - arr[0]) / gcd + 1 - n);
	return 0;
}