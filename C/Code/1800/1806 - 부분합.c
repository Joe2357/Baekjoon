#include <stdio.h>

#define MAX_IDX 100000

int arr[MAX_IDX];
int n;

int sum, s;
int l, r;
int result = MAX_IDX + 1;

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	while (r <= n) {
		if (sum >= s) {
			result = min(result, r - l);
			sum -= arr[l++];
		} else {
			sum += arr[r++];
		}
	}

	if (result > MAX_IDX) {
		printf("0");
	} else {
		printf("%d", result);
	}
	return 0;
}