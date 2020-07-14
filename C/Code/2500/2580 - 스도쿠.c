#include <stdio.h>

int did;

void back(int arr[][9]) {
	if (did)						// already had solution
		return;
	int temparr[9][9];
	for (int i = 0; i < 81; i++)	// array copy
		temparr[i / 9][i % 9] = arr[i / 9][i % 9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!temparr[i][j]) {						// if empty slot
				int tarr[10] = { 0 };					// 1 ~ 9 slot
				for (int a = 0; a < 9; a++)				// row count
					tarr[arr[i][a]] = 1;
				for (int a = 0; a < 9; a++)				// column count
					tarr[arr[a][j]] = 1;
				for (int a = i / 3 * 3; a < i / 3 * 3 + 3; a++)			// 3 * 3 square area count
					for (int b = j / 3 * 3; b < j / 3 * 3 + 3; b++)
						tarr[arr[a][b]] = 1;
				for (int a = 1; a < 10; a++)							// number count
					if (!tarr[a]) {										// if that number didn't used
						temparr[i][j] = a;								// insert that number
						back(temparr, getResult);						// backtracking
					}
				return;													// if there were at least 1 empty slot
			}
		}
	}
	for (int i = 0; i < 9; i++) {										// print array
		for (int j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	did = 1;															// all backtracking stop command
	return;
}

int main() {
	int arr[9][9];
	for (int i = 0; i < 81; i++)
		scanf("%d", &arr[i / 9][i % 9]);
	back(arr);
	return 0;
}