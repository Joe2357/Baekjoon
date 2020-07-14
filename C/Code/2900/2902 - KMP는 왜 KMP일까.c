#include <stdio.h>

int main() {
	char str[110];
	scanf("%s", str);
	for (int i = 0; str[i]; i++)    // while end of string
		if (str[i] >= 'A' && str[i] <= 'Z') // if CAPITAL alphabet
			printf("%c", str[i]);   // print alphabet
	return 0;
}