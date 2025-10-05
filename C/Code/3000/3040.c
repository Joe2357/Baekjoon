#include <stdio.h>

#define MAX_IDX 9
const int TARGET = 100;

int dwarf[MAX_IDX];

int main() {
	int sum = 0;
	for (int i = 0; i < MAX_IDX; ++i) {
		scanf("%d", dwarf + i);
		sum += dwarf[i];
	}

	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = i + 1; j < MAX_IDX; ++j) {
			if (sum - dwarf[i] - dwarf[j] == TARGET) {
				for (int k = 0; k < MAX_IDX; ++k) {
					if (k != i && k != j) {
						printf("%d\n", dwarf[k]);
					}
				}
				return 0;
			}
		}
	}
	return 0;
}