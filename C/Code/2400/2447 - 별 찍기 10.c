#include <stdio.h>
#include <math.h>

int arr[6561][6561];

void star(int num, int x, int y) {
	if (num == 1) {
		/*
			###
			# #
			###
		*/
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				arr[y + i][x + j] = 1;		// 3 * 3 square
		arr[y + 1][x + 1] = 0;				// erase middle
		return;
	}
	else {
		num--;
		for (int i = 0; i < 3; i++)			// recursive 3 * 3 square
			for (int j = 0; j < 3; j++)
				if (i == 1 && j == 1)		// erase middle
					continue;
				else
					star(num, x + pow(3, num) * i, y + pow(3, num) * j);	// recursive
		return;
	}
}

void print(int n) {
	int x, y = 0;
	while (y < n) {			// print row
		x = 0;
		while (x < n) {		// print column
			if (arr[y][x])
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		printf("\n");
	}
	return;
}

int main(n) {
	scanf("%d", &n);
	int k = 0, temp = n;
	while (temp / 3)		// n = 3 ^ k
		temp /= 3, k++;
	star(k, 0, 0);
	print(n);
	return 0;
}