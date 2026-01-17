#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(5e5)
const int INF = 987654321;
const char RED = 'R', BLUE = 'B';

char grid[MAX_IDX + 1];
int n;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	scanf("%d %s", &n, grid);

	int ret = INF, tmp_result;
	bool opposite_appeared;

	// 1. red to left
	tmp_result = 0;
	opposite_appeared = false;
	for (int i = 0; i < n; ++i) {
		tmp_result += (grid[i] == RED && opposite_appeared);
		opposite_appeared |= (grid[i] == BLUE);
	}
	ret = min(ret, tmp_result);

	// 2. red to right
	tmp_result = 0;
	opposite_appeared = false;
	for (int i = n - 1; i >= 0; --i) {
		tmp_result += (grid[i] == RED && opposite_appeared);
		opposite_appeared |= (grid[i] == BLUE);
	}
	ret = min(ret, tmp_result);

	// 3. blue to left
	tmp_result = 0;
	opposite_appeared = false;
	for (int i = 0; i < n; ++i) {
		tmp_result += (grid[i] == BLUE && opposite_appeared);
		opposite_appeared |= (grid[i] == RED);
	}
	ret = min(ret, tmp_result);

	// 4. blue to right
	tmp_result = 0;
	opposite_appeared = false;
	for (int i = n - 1; i >= 0; --i) {
		tmp_result += (grid[i] == BLUE && opposite_appeared);
		opposite_appeared |= (grid[i] == RED);
	}
	ret = min(ret, tmp_result);

	printf("%d", ret);
	return 0;
}