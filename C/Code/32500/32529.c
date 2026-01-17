#include <stdio.h>

#define MAX_IDX (int)(1e5)

int n, m;
int arr[MAX_IDX];

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	return;
}

int main() {
	read_input();

	int sum = 0;
	for (int i = n - 1; i >= 0; --i) {
		sum += arr[i];
		if (sum >= m) {
			printf("%d", i + 1);
			return 0;
		}
	}

	printf("-1");
	return 0;
}