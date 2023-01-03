#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100
bool arr[MAX_IDX + 2];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}

	int k;
	scanf("%d", &k);
	while (k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		switch (a) {
			case 1: {
				for (int i = b; i <= n; i += b) {
					arr[i] = !arr[i];
				}
			} break;

			case 2: {
				arr[b] = !arr[b];
				for (int i = 1; b - i > 0 && b + i <= n; ++i) {
					if (arr[i + b] == arr[b - i]) {
						arr[i + b] = !arr[i + b];
						arr[b - i] = !arr[b - i];
					} else {
						break;
					}
				}
			} break;
		}
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", arr[i]);
		if (i % 20 == 0) {
			printf("\n");
		}
	}
	return 0;
}