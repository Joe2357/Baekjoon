#include <stdio.h>

int main() {
	char arr[5][16] = { 0 };
	for (int i = 0; i < 5; i++)
		scanf("%s", arr[i]);
	for (int i = 0; i < 15; i++) // brute force
		for (int j = 0; j < 5; j++)
			if (arr[j][i])				 // if not null
				printf("%c", arr[j][i]); // print value
	return 0;
}