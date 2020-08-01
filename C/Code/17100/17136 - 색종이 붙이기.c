#include <stdio.h>
#define min(a, b) (a > b) ? b : a

int result = 999;

// brute force backtrack
void back(int arr[][10], int *count, int y) {
	// backtrack init
	int tarr[10][10], tcount[6];
	for (int i = 0; i < 100; i++)
		tarr[i / 10][i % 10] = arr[i / 10][i % 10];
	for (int i = 0; i < 5; i++)
		tcount[i + 1] = count[i + 1];

	// backtrack start
	for (int i = y; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (arr[i][j]) { // is there is a block to hide
				int aboolean = 0;
				for (int a = 5; a; a--) { // check size
					int boolean = 1;
					for (int b = 0; b < a; b++)
						for (int c = 0; c < a; c++)
							if (i + b >= 10 || j + c >= 10) { // out of range
								boolean = 0;
								break;
							}
							else
								boolean *= tarr[i + b][j + c];
					if (boolean) { // have a chance
						aboolean = 1;

						if (tcount[a] == 5) // already used all paper
							continue;

						// backtrack
						for (int b = 0; b < a; b++)
							for (int c = 0; c < a; c++)
								tarr[i + b][j + c] = 0;
						tcount[a]++;
						back(tarr, tcount, i);
						for (int b = 0; b < a; b++)
							for (int c = 0; c < a; c++)
								tarr[i + b][j + c] = 1;
						tcount[a]--;
					}
				}
				if (aboolean) // still left some block to hide
					return;
			}

	// get result
	int r = 0;
	for (int i = 1; i < 6; i++)
		r += tcount[i];
	result = min(result, r);
	return;
}

int main() {
	// init
	int arr[10][10], count[6] = { 0 };
	for (int i = 0; i < 100; i++)
		scanf("%d", &arr[i / 10][i % 10]);

	// backtrack
	back(arr, count, 0);

	// print result
	printf("%d", (result == 999) ? -1 : result);
	return 0;
}