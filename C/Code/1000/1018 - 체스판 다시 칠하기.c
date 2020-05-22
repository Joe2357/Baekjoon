#include <stdio.h>
 
int main() {
	char arr[51][51], c;
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++)
		scanf("%s", arr[i]);							// making greed
	int min = 64;										// max will be 64
	for (int i = 0; i <= x - 8; i++) {					// brute-force search
		for (int j = 0; j <= y - 8; j++) {
			int maybe, temp = arr[i][j];
			maybe = 0;									// maybe = have to change in situation
			for (int a = 0; a < 8; a++) {				// case starts 'W'
				for (int b = 0; b < 8; b++) {
					if (arr[i + a][j + b] != temp)
						maybe++;
					temp = (temp == 'B') ? 'W' : 'B';
				}
				temp = (temp == 'B') ? 'W' : 'B';
			}
			if (maybe < min)
				min = maybe;
			maybe = 0;
			temp = (temp == 'B') ? 'W' : 'B';
			for (int a = 0; a < 8; a++) {				// case starts 'B'
				for (int b = 0; b < 8; b++) {
					if (arr[i + a][j + b] != temp)
						maybe++;
					temp = (temp == 'B') ? 'W' : 'B';
				}
				temp = (temp == 'B') ? 'W' : 'B';
			}
			if (maybe < min)
				min = maybe;
		}
	}
	printf("%d", min);
	return 0;
}