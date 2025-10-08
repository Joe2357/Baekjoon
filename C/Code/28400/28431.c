#include <stdio.h>

#define MAX_IDX 10

int socks[MAX_IDX];

int main() {
	for (int i = 0; i < 5; ++i) {
		int a;
		scanf("%d", &a);
		socks[a] += 1;
	}

	for (int i = 0; i < MAX_IDX; ++i) {
		if (socks[i] % 2 == 1) {
			printf("%d", i);
		}
	}

	return 0;
}