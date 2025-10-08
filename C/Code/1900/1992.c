#include <stdio.h>

char arr[64][65];

void check(int x, int y, int a) {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			if (arr[x + i][y + j] != arr[x][y]) {
				printf("(");
				check(x, y, a / 2);
				check(x, y + a / 2, a / 2);
				check(x + a / 2, y, a / 2);
				check(x + a / 2, y + a / 2, a / 2);
				printf(")");
				return;
			}
	printf("%c", arr[x][y]);
	return;
}

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	check(0, 0, n);
	return 0;
}