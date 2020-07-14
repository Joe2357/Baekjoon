#include <stdio.h>

char arr[64][65];		// number connected

void check(int x, int y, int a) {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			if (arr[x + i][y + j] != arr[x][y]) {		// if no condition
				printf("(");							// start divide
				check(x, y, a / 2);						// left top
				check(x, y + a / 2, a / 2);				// right top
				check(x + a / 2, y, a / 2);				// left bottom
				check(x + a / 2, y + a / 2, a / 2);		// right bottom
				printf(")");							// conquer
				return;
			}
	printf("%c", arr[x][y]);							// if condition
	return;
}

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)		// input grid
		scanf("%s", arr[i]);		// not number, string!
	check(0, 0, n);					// divide & conquer
	return 0;
}