#include <stdio.h>

int arr[2187][2187], paper[3];	// 3 ^ 7 = 2187, paper[x] = (x - 1)'s count

void check(int x, int y, int a) {
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			if (arr[x + i][y + j] != arr[x][y]) {		// start divide
				int temp = a / 3;						// divide 9 pieces
				for (int k = 0; k < a; k += temp)		// x range
					for (int l = 0; l < a; l += temp)	// y range
						check(x + k, y + l, temp);
				return;
			}
	paper[arr[x][y] + 1]++;								// add paper count
	return;
}

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)							// input
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	check(0, 0, n);										// divide & conquer
	printf("%d\n%d\n%d", paper[0], paper[1], paper[2]);	// print result
	return 0;
}