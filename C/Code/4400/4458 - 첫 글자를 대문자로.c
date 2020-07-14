#include <stdio.h>

int main(t) {
	for (scanf("%d ", &t); t; t--) {
		char str[31];
		gets(str);                                              // input string include ' '
		printf("%c%s\n", str[0] - 32 * (str[0] > 96), &str[1]); // only first letter turns to capital letter
	}
	return 0;
}