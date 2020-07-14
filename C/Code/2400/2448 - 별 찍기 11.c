#include <stdio.h>
#include <math.h>

int arr[8000][8000];	// grid

void star(int a, int x, int y) {		// recursive function
	if (a == 1) {
		/* elemental shape
			  #
			 # #
			#####
		*/
		arr[y][x + 2] = 1; arr[y + 1][x + 1] = 1; arr[y + 1][x + 3] = 1;
		for (int i = 0; i < 5; i++)
			arr[y + 2][x + i] = 1;
		return;
	}
	else {										// recursive
		int temp = 3 * pow(2, a - 2);
		star(a - 1, x + temp, y);
		star(a - 1, x, y + temp);
		star(a - 1, x + temp * 2, y + temp);
		return;
	}
}

void print(int n) {
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++)
			if (arr[i][j])
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
	return;
}

int main(n) {
	scanf("%d", &n);
	int temp = n / 3, a = 0;
	while (temp)
		temp /= 2, a++;
	star(a, 0, 0);
	print(n);
	return 0;
}