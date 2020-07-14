#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[2][26] = { 0 }, i = 0, result = 0;	// alphabet
	while (i != 2) {
		char c = getchar();
		if (c == '\n')							// goto next
			i++;
		else									// count alphabet
			arr[i][c - 'a']++;
	}
	for (i = 0; i < 26; i++)					// for all alphabet
		result += abs(arr[0][i] - arr[1][i]);	// add different count
	printf("%d", result);
	return 0;
}