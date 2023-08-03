#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 50
char grid[MAX_IDX][MAX_IDX + 1];
int n, m, k;

const char ON = '1';
const char OFF = '0';

bool string_compare(int a, int b) {
	for (int i = 0; i < m; ++i) {
		if (grid[a][i] != grid[b][i]) {
			return false;
		}
	}
	return true;
}

#define max(a, b) (((a) > (b)) ? (a) : (b))
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}
	scanf("%d", &k);

	int result = 0;
	for (int i = 0; i < n; ++i) {
		int offCount = 0;
		for (int j = 0; j < m; ++j) {
			offCount += (grid[i][j] == OFF);
		}

		if (offCount <= k && offCount % 2 == k % 2) {
			int sameCount = 1;
			for (int j = 0; j < i; ++j) {
				sameCount += (string_compare(i, j));
			}
			result = max(result, sameCount);
		}
	}

	printf("%d", result);
	return 0;
}