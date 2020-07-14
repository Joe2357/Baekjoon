#include <stdio.h>

int main() {
	char str[101];
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
		if (str[i] >= 'A' && str[i] <= 'Z') // 'A' ~ 'Z'
			printf("%c", str[i] + 32);
		else                                // 'a' ~ 'z'
			printf("%c", str[i] - 32);
	return 0;
}