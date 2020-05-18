#include <stdio.h>

void DFS(int arr[][50], int x, int y, int horizon, int vertical) {
	if (x < 0 || y < 0 || x >= horizon || y >= vertical)				// out of greed
		return;
	else if (arr[y][x]) {
		arr[y][x] = 0;													// remove value ( already visited )
		DFS(arr, x - 1, y, horizon, vertical);							// spread up
		DFS(arr, x + 1, y, horizon, vertical);							// spread down
		DFS(arr, x, y - 1, horizon, vertical);							// spread left
		DFS(arr, x, y + 1, horizon, vertical);							// spread right
		return;
	}
	else
		return;
}

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int arr[50][50] = { 0 }, x, y, cabbage;
		scanf("%d %d %d", &x, &y, &cabbage);
		for (; cabbage; cabbage--) {
			int xtemp, ytemp;
			scanf("%d %d", &xtemp, &ytemp);
			arr[ytemp][xtemp] = 1;										// making greed
		}
		int result = 0;
		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
				if (arr[i][j]) {
					result++;											// add 1 to result
					DFS(arr, j, i, x, y);								// DFS
				}
		printf("%d\n", result);
	}
	return 0;
}
