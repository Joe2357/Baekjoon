#include <stdio.h>

/*
	result[0][0] = arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0]
	result[1][0] = arr1[1][0] * arr2[0][0] + arr1[1][1] * arr2[1][0]
	result[2][0] = arr1[2][0] * arr2[0][0] + arr1[2][1] * arr2[1][0]

	result[0][1] = arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1]
	result[1][1] = arr1[1][0] * arr2[0][1] + arr1[1][1] * arr2[1][1]
	result[2][1] = arr1[2][0] * arr2[0][1] + arr1[2][1] * arr2[1][1]

	result[0][2] = arr1[0][0] * arr2[0][2] + arr1[0][1] * arr2[1][2]
	result[1][2] = arr1[1][0] * arr2[0][2] + arr1[1][1] * arr2[1][2]
	result[2][2] = arr1[2][0] * arr2[0][2] + arr1[2][1] * arr2[1][2]

	result[i][j] = arr[i][?] * arr2[?][j] + arr1[i][?] * arr2[?][j] -> sum of (arr1[i][x] * arr2[a][j])
*/

int main(n, m, k) {
	int arr1[100][100], arr2[100][100], result[100][100];
	scanf("%d %d", &n, &m);             // matrix 1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr1[i][j]);
	scanf("%d %d", &m, &k);             // matrix 2
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			scanf("%d", &arr2[i][j]);
	for (int i = 0; i < n; i++)			// Matrix multiplication
		for (int j = 0; j < k; j++) {
			int temp = 0;
			for (int a = 0; a < m; a++) {
				temp += arr1[i][a] * arr2[a][j];
			}
			result[i][j] = temp;        // store value to result matrix
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
	return 0;
}