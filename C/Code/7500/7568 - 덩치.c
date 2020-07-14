#include <stdio.h>

int main() {
	int arr[50][3] = { 0 }, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) // brute force
			if (i == j)
				continue;
			else if ((arr[i][0] < arr[j][0]) && (arr[i][1] < arr[j][1]))
				arr[i][2]++;
	for (int i = 0; i < n; i++)
		printf("%d ", ++arr[i][2]);
	return 0;
}