#include <stdio.h>

int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} },
arr[50][50], h, w;

void DFS(int y, int x) {
	// out of grid
	if (x < 0 || y < 0 || y == h || x == w)
		return;

	// if position is an unvisited island
	if (arr[y][x]) {
		// check visited
		arr[y][x] = 0;
		// DFS searching
		for (int i = 0; i < 8; i++)
			DFS(y + dir[i][0], x + dir[i][1]);
	}
	return;
}

int main(r) {
	// while end process
	while (scanf("%d %d", &w, &h) && w && h) {
		// input
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &arr[i][j]);

		// test case calc
		r = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (arr[i][j]) {
					DFS(i, j);
					r++;
				}
		printf("%d\n", r);
	}
	return 0;
}