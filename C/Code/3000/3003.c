#include <stdio.h>

#define MAX_PIECE 6

const int std_piece[MAX_PIECE] = {1, 1, 2, 2, 2, 8};
int have[MAX_PIECE];

int main() {
	for (int i = 0; i < MAX_PIECE; ++i) {
		scanf("%d", &have[i]);
	}
	for (int i = 0; i < MAX_PIECE; ++i) {
		printf("%d ", std_piece[i] - have[i]);
	}
	return 0;
}