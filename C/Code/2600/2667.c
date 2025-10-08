#include <stdio.h>

int DFS(char arr[][26], int y, int x, int n) {
	if (x < 0 || y < 0 || x == n || y == n)
		return 0;
	if (arr[y][x] == '1') {
		arr[y][x] = '0';
		int b = 1 + DFS(arr, y, x - 1, n) + DFS(arr, y, x + 1, n) + DFS(arr, y - 1, x, n) + DFS(arr, y + 1, x, n);
		return b;
	}
	return 0;
}

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main(n, i, j, a) {
	char arr[26][26];
	int intarr[625];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", arr[i]);
	for (i = 0, a = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (arr[i][j] == '1')
				intarr[a++] = DFS(arr, i, j, n);
	qsort(intarr, a, 4, cmp);
	printf("%d\n", a);
	for (i = 0; i < a; i++)
		printf("%d\n", intarr[i]);
	return 0;
}