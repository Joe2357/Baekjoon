#include <stdio.h>

void spread(int arr[][50], int y, int x) {
	int temparr[50][50] = { 0 };
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (arr[i][j] == -1)
				continue;
			if (arr[i][j] / 5) {
				int temp = arr[i][j] / 5;
				if (i && arr[i - 1][j] != -1)
					temparr[i - 1][j] += temp, arr[i][j] -= temp;
				if (i + 1 != y && arr[i + 1][j] != -1)
					temparr[i + 1][j] += temp, arr[i][j] -= temp;
				if (j && arr[i][j - 1] != -1)
					temparr[i][j - 1] += temp, arr[i][j] -= temp;
				if (j + 1 != x && arr[i][j + 1] != -1)
					temparr[i][j + 1] += temp, arr[i][j] -= temp;
			}
		}
	}
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			arr[i][j] += temparr[i][j];
	return;
}

void blow(int arr[][50], int y, int x, int clean) {
	for (int i = clean - 1; i > 0; i--)
		arr[i][0] = arr[i - 1][0];
	for (int i = 0; i < x - 1; i++)
		arr[0][i] = arr[0][i + 1];
	for (int i = 0; i < clean; i++)
		arr[i][x - 1] = arr[i + 1][x - 1];
	for (int i = x - 1; i > 1; i--)
		arr[clean][i] = arr[clean][i - 1];
	arr[clean][1] = 0;
	for (int i = clean + 2; i < y - 1; i++)
		arr[i][0] = arr[i + 1][0];
	for (int i = 0; i < x - 1; i++)
		arr[y - 1][i] = arr[y - 1][i + 1];
	for (int i = y - 1; i > clean; i--)
		arr[i][x - 1] = arr[i - 1][x - 1];
	for (int i = x - 1; i > 1; i--)
		arr[clean + 1][i] = arr[clean + 1][i - 1];
	arr[clean + 1][1] = 0;
	return;
}

int main() {
	// init
	int arr[50][50] = { 0 }, r, c, t, clean = -1;
	scanf("%d %d %d", &r, &c, &t);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
			if (temp == -1 && clean == -1)
				clean = i;
		}

	// simulate
	for (int i = 0; i < t; i++) {
		spread(arr, r, c);
		blow(arr, r, c, clean);
	}

	// get result
	int result = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (arr[i][j] != -1)
				result += arr[i][j];

	// print result
	printf("%d", result);
	return 0;
}