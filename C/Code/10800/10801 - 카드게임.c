#include <stdio.h>

int main() {
	int arr[2][10], a = 0, b = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < 10; i++)
		if (arr[0][i] > arr[1][i])
			a++;
		else if (arr[0][i] < arr[1][i])
			b++;
	if (a > b)
		printf("A");
	else if (a < b)
		printf("B");
	else
		printf("D");
	return 0;
}