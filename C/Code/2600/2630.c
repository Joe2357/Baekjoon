#include <stdio.h>

int arr[128][128], paper[2];

void check(int x, int y, int a) {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			if (arr[x + i][y + j] != arr[x][y]) {
				check(x, y, a / 2);
				check(x + a / 2, y, a / 2);
				check(x, y + a / 2, a / 2);
				check(x + a / 2, y + a / 2, a / 2);
				return;
			}
	paper[arr[x][y]]++;
	return;
}

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	check(0, 0, n);
	printf("%d\n%d", paper[0], paper[1]);
	return 0;
}