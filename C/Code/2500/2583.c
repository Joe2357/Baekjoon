#include <stdio.h>
#define DEBUG 0

int arr[100][100], m, n, temp;

int cmp(int* a, int* b) {
	return *a - *b;
}

void DFS(int y, int x) {
	if (x < 0 || y < 0 || x == n || y == m || arr[y][x])
		return;
	arr[y][x] = 1, temp++;
	DFS(y - 1, x);
	DFS(y + 1, x);
	DFS(y, x - 1);
	DFS(y, x + 1);
	return;
}

int main(k) {
	int width[10000], rear = 0;
	for (scanf("%d%d %d", &m, &n, &k); k; k--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = b; i < d; i++)
			for (int j = a; j < c; j++)
				arr[i][j] = 1;
	}
	for (int a = 0; a < m; a++)
		for (int b = 0; b < n; b++)
			if (!arr[a][b]) {
				temp = 0;
				DFS(a, b);
				width[rear++] = temp;
			}
	qsort(width, rear, sizeof(int), cmp);
	printf("%d\n", rear);
	for (int i = 0; i < rear; i++)
		printf("%d ", width[i]);
	return 0;
}