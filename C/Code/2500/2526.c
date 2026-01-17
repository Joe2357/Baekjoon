#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
const int NONE = -1;

int visited_sequence[MAX_IDX + 1];

void init() {
	for (int i = 0; i <= MAX_IDX; i++) {
		visited_sequence[i] = NONE;
	}
	return;
}

int main() {
	int n, p;
	scanf("%d %d", &n, &p);
	init();

	int current_value = n;
	for (int idx = 0; true; ++idx) {
		if (visited_sequence[current_value] != NONE) {
			printf("%d", idx - visited_sequence[current_value]);
			break;
		} else {
			visited_sequence[current_value] = idx;
			current_value = (current_value * n) % p;
		}
	}
	return 0;
}