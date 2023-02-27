#include <stdio.h>

#define MAX_IDX (50 + 1)
char grid[MAX_IDX][MAX_IDX];
int n, m;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define INF 100
#define CHESS_SIZE 8

int main() {
	int retval = INF;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}

	// brute force
	for (int i = 0; i <= n - CHESS_SIZE; ++i) {
		for (int j = 0; j <= m - CHESS_SIZE; ++j) {
			// case 1. first position is white
			int tempResult = 0;
			for (int a = 0; a < CHESS_SIZE; ++a) {
				for (int b = 0; b < CHESS_SIZE; ++b) {
					switch ((a + b) % 2) {
						case 0: {
							if (grid[i + a][j + b] != 'W') {
								++tempResult;
							}
							break;
						}
						case 1: {
							if (grid[i + a][j + b] != 'B') {
								++tempResult;
							}
							break;
						}
					}
				}
			}
			retval = min(retval, tempResult);

			// case 2. first position is black
			tempResult = 0;
			for (int a = 0; a < CHESS_SIZE; ++a) {
				for (int b = 0; b < CHESS_SIZE; ++b) {
					switch ((a + b) % 2) {
						case 0: {
							if (grid[i + a][j + b] != 'B') {
								++tempResult;
							}
							break;
						}
						case 1: {
							if (grid[i + a][j + b] != 'W') {
								++tempResult;
							}
							break;
						}
					}
				}
			}
			retval = min(retval, tempResult);
		}
	}

	printf("%d", retval);
	return 0;
}