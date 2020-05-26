#include <stdio.h>
#include <string.h>
#define min(a, b) (a > b) ? b : a

int main() {
	int result = 51;							// max value
	char str[2][51] = { 0 };
	scanf("%s %s", str[0], str[1]);				// input
	for (int i = 0; i <= strlen(str[1]) - strlen(str[0]); i++) {	// brute force
		int temp = 0;
		for (int j = 0; str[0][j]; j++)								// while end of string A
			temp += !!(str[0][j] - str[1][i + j]);					// add 1 if alphabet is not same
		result = min(result, temp);									// change minimum value
	}
	printf("%d", result);
	return 0;
}