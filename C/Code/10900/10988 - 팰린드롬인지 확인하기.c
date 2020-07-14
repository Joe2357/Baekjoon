#include <stdio.h>

int main() {
	char str[101];
	scanf("%s", str);
	int i, j;
	for (j = 0; str[j]; j++); // check string length
	for (i = 0, j -= 1; i < j; i++, j--)
		if (str[i] != str[j]) { // not palindrome
			printf("0");
			return 0;
		}
	printf("1");
	return 0;
}