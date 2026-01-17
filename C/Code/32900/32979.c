#include <stdio.h>

#define MAX_IDX 80

int arr[MAX_IDX];
int n, t;

void read_input() {
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n * 2; ++i) {
		scanf("%d", &arr[i]);
	}
	return;
}

int main() {
	read_input();

	int current_idx = 0;
	while (t--) {
		int b;
		scanf("%d", &b);
		current_idx = (current_idx + b - 1) % (n * 2);
		printf("%d ", arr[current_idx]);
	}
	return 0;
}