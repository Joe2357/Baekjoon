#include <stdio.h>

int arr[100][100], m, n, temp;

int cmp(int* a, int* b) {
	return *a - *b;
}

void DFS(int y, int x) {									// recursive DFS function
	if (x < 0 || y < 0 || x == n || y == m || arr[y][x])	// out of grid
		return;
	arr[y][x] = 1, temp++;									// visited check
	DFS(y - 1, x);
	DFS(y + 1, x);
	DFS(y, x - 1);
	DFS(y, x + 1);
	return;
}

int main(k) {
	int width[10000], rear = 0;
	for (scanf("%d%d %d", &m, &n, &k); k; k--) {	// square input
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = b; i < d; i++)					// square draw
			for (int j = a; j < c; j++)
				arr[i][j] = 1;
	}
	for (int a = 0; a < m; a++)
		for (int b = 0; b < n; b++)
			if (!arr[a][b]) {						// if empty space
				temp = 0;
				DFS(a, b);
				width[rear++] = temp;				// empty area's width
			}
	qsort(width, rear, sizeof(int), cmp);			// sort ascending
	printf("%d\n", rear);
	for (int i = 0; i < rear; i++)
		printf("%d ", width[i]);
	return 0;
}