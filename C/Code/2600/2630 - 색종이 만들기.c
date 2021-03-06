#include <stdio.h>

int arr[128][128], paper[2];

void check(int x, int y, int a) {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			if (arr[x + i][y + j] != arr[x][y]) {
				check(x, y, a / 2);                     // left-up ( 1/4 )
				check(x + a / 2, y, a / 2);             // left-down ( 1/4 )
				check(x, y + a / 2, a / 2);             // right-up ( 1/4 )
				check(x + a / 2, y + a / 2, a / 2);     // right-down ( 1/4 )
				return;                                 // paper couldn't created
			}
	paper[arr[x][y]]++;                                 // paper created
	return;
}

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);            // grid store
	check(0, 0, n);                             // divide & conquer
	printf("%d\n%d", paper[0], paper[1]);       // paper count print
	return 0;
}