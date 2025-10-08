#include <math.h>
#include <stdio.h>
#include <string.h>

int main(t) {
	char str[2][11];
	int arr[2][26] = {0}, i = 0, result = 0;
	scanf("%d %s", &t, str[0]);
	while (str[0][i])
		arr[0][str[0][i++] - 'A']++; // alphabet count
	for (--t; t; t--) {				 // already 1 word was given
		int temp = 0;
		for (i = 0; i < 26; i++) // clear
			arr[1][i] = 0;
		scanf("%s", str[1]);
		if (abs(strlen(str[0]) - strlen(str[1])) > 1) // if length of word out of range
			continue;
		i = 0;
		while (str[1][i]) // temp word alphabet count
			arr[1][str[1][i++] - 'A']++;
		for (i = 0; i < 26; i++) // temp = difference of 2 word's alphabet
			temp += abs(arr[0][i] - arr[1][i]);
		result += (temp < 3); // max range = 2 ( can change 1 alphabet )
	}
	printf("%d", result);
	return 0;
}