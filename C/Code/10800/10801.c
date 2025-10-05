#include <stdio.h>

#define MAX_IDX 10

int card[2][MAX_IDX];

int main() {
	for (int i = 0; i < MAX_IDX; ++i) {
		scanf("%d", &card[0][i]);
	}
	for (int i = 0; i < MAX_IDX; ++i) {
		scanf("%d", &card[1][i]);
	}

	int win_a = 0, win_b = 0;
	for (int i = 0; i < MAX_IDX; ++i) {
		win_a += (card[0][i] > card[1][i]);
		win_b += (card[0][i] < card[1][i]);
	}

	if (win_a > win_b) {
		printf("A");
	} else if (win_a < win_b) {
		printf("B");
	} else {
		printf("D");
	}
	return 0;
}