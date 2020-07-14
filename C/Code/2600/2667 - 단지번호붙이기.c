#include <stdio.h>

char arr[26][26];
int n;

int DFS(int y, int x) {
	if (x < 0 || y < 0 || x == n || y == n)     // out of grid
		return 0;
	if (arr[y][x] == '1') {                     // if house is in that pos
		arr[y][x] = '0';                        // visit check
		return DFS(arr, y, x - 1, n) +          // visit all
			DFS(arr, y, x + 1, n) +
			DFS(arr, y - 1, x, n) +
			DFS(arr, y + 1, x, n) + 1;           // +1 = current house
	}
	return 0;                                   // no house in current pos
}

int cmp(int* a, int* b) {
	return *a - *b;
}

int main(i, j, a) {
	int intarr[625];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", arr[i]);
	for (i = 0, a = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (arr[i][j] == '1')
				intarr[a++] = DFS(arr, i, j, n);    // DFS counting
	qsort(intarr, a, sizeof(int), cmp);             // ascending sort
	printf("%d\n", a);                              // complex count
	for (i = 0; i < a; i++)                         // number of house in complex
		printf("%d\n", intarr[i]);
	return 0;
}