#include <stdio.h>

void back(int arr[][9], int* getResult) {
	if (*getResult)
		return;
	int temparr[9][9];
	for (int i = 0; i < 81; i++)
		temparr[i / 9][i % 9] = arr[i / 9][i % 9];
	for (int i = 0; i < 9; i++) {
		int boolean = 0;
		for (int j = 0; j < 9; j++) {
			if (!temparr[i][j]) {
				int tarr[10] = { 0 };
				for (int a = 0; a < 9; a++)
					tarr[arr[i][a]] = 1;
				for (int a = 0; a < 9; a++)
					tarr[arr[a][j]] = 1;
				for (int a = i / 3 * 3; a < i / 3 * 3 + 3; a++)
					for (int b = j / 3 * 3; b < j / 3 * 3 + 3; b++)
						tarr[arr[a][b]] = 1;
				for (int a = 1; a < 10; a++)
					if (!tarr[a]) {
						temparr[i][j] = a;
						back(temparr, getResult);
					}
				return;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	*getResult = 1;
	return;
}

int main() {
	int arr[9][9], getResult = 0;
	for (int i = 0; i < 81; i++)
		scanf("%d", &arr[i / 9][i % 9]);
	back(arr, &getResult);
	return 0;
}