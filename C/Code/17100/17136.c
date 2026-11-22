#include <stdio.h>
#define min(a, b) (a > b) ? b : a

int result = 999;

void back(int arr[][10], int* count, int y) {
	int tarr[10][10], tcount[6];
	for (int i = 0; i < 100; i++)
		tarr[i / 10][i % 10] = arr[i / 10][i % 10];
	for (int i = 0; i < 5; i++)
		tcount[i + 1] = count[i + 1];
	for (int i = y; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (arr[i][j]) {
				int aboolean = 0;
				for (int a = 5; a; a--) {
					int boolean = 1;
					for (int b = 0; b < a; b++)
						for (int c = 0; c < a; c++)
							if (i + b >= 10 || j + c >= 10) {
								boolean = 0;
								break;
							}
							else
								boolean *= tarr[i + b][j + c];
					if (boolean) {
						if (tcount[a] == 5) {
							aboolean = 1;
							continue;
						}
						aboolean = 1;
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
				if (aboolean)
					return;
			}
	int r = 0;
	for (int i = 1; i < 6; i++)
		r += tcount[i];
	result = min(result, r);
	return;
}

int main() {
	int arr[10][10], count[6] = { 0 };
	for (int i = 0; i < 100; i++)
		scanf("%d", &arr[i / 10][i % 10]);
	back(arr, count, 0);
	printf("%d", (result == 999) ? -1 : result);
	return 0;
}