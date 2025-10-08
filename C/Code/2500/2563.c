#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_SIZE 100
const int PAPER_SIZE = 10;

bool isBlack[MAX_SIZE + 1][MAX_SIZE + 1 + 1];

int main() {
	int ret = 0, t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int x = a; x < a + PAPER_SIZE; ++x) {
			for (int y = b; y < b + PAPER_SIZE; ++y) {
				isBlack[x][y] = true;
			}
		}
	}
	for (int i = 0; i <= MAX_SIZE; ++i) {
		for (int j = 0; j <= MAX_SIZE; ++j) {
			ret += isBlack[i][j];
		}
	}
	printf("%d", ret);
	return 0;
}