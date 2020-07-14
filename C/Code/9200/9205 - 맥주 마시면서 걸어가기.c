#include <stdio.h>
#include <string.h>

int main() {
	char str[4][1010] = { "0", "0" };
	scanf("%s %s", str[2], str[3]); // string input
	strcat(str[0], str[2]), strcat(str[1], str[3]); // "0" + string, So all strings are starts with "0"
	int arr[1010][1010] = { 0 }; // matrix
	for (int i = 0; i < strlen(str[0]); i++)
		for (int j = 0; j < strlen(str[1]); j++) {
			if (!i || !j) // "0" part, should not match
				arr[i][j] = 0;
			else if (str[0][i] == str[1][j]) // common subsequence
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else // find the longest subsequenceabove or left
				arr[i][j] = (arr[i - 1][j] > arr[i][j - 1]) ? arr[i - 1][j] : arr[i][j - 1];
		}
	printf("%d", arr[strlen(str[0]) - 1][strlen(str[1]) - 1]); // print LCS
	return 0;
}