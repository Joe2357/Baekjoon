#include <stdio.h>
#include <string.h>

int main() {
	char str_1[101], str_2[101];
	int i = 0;
	char c = getchar();

	while (c != '\n') { // only get alphabet
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			str_1[i++] = c;
		c = getchar();
	}
	str_1[i] = '\0';

	scanf("%s", str_2);

	if (strstr(str_1, str_2) != NULL)
		printf("1");
	else
		printf("0");
	return 0;
}