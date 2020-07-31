#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b) ? a : b

int main() {
	// init
	char str[2][10010] = { 0 };
	scanf("%s %s", str[0], str[1]);
	int result[10010] = { 0 }, Max = max(strlen(str[0]), strlen(str[1]));

	// add two strings
	for (int i = 0; i < 2; i++) {
		for (int j = 0; str[i][j]; j++)
			result[Max - strlen(str[i]) + j] += (str[i][j] - '0');
		for (int j = Max; j; j--) // over 10
			if (result[j] / 10)
				result[j - 1] += result[j] / 10, result[j] %= 10;
	}

	// print result
	for (int i = 0; i < Max; i++)
		printf("%d", result[i]);
	return 0;
}