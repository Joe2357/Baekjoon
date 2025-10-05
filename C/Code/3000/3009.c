#include <stdio.h>

int main() {
	int arr[3][2] = {0};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", arr[i] + j);
	int x, y, xtemp, ytemp;

	if (!(arr[0][0] - arr[1][0]))
		x = arr[0][0], xtemp = arr[2][0] + arr[0][0];
	else if (!(arr[0][0] - arr[2][0]))
		x = arr[0][0], xtemp = arr[1][0] + arr[0][0];
	else
		x = arr[1][0], xtemp = arr[0][0] + arr[1][0];

	if (!(arr[0][1] - arr[1][1]))
		y = arr[0][1], ytemp = arr[2][1] + arr[0][1];
	else if (!(arr[0][1] - arr[2][1]))
		y = arr[0][1], ytemp = arr[1][1] + arr[0][1];
	else
		y = arr[1][1], ytemp = arr[0][1] + arr[1][1];

	printf("%d %d", xtemp - x, ytemp - y);
	return 0;
}