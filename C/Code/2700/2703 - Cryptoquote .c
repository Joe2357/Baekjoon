#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		char str[1001], c, cry[27];
		c = getchar();                              // flush input buffer
		gets(str);                                  // get string including ' '
		scanf("%s", cry);                           // alphabet crypte rule
		for (int i = 0; str[i]; i++)
			if (str[i] == ' ')                      // space not changed
				printf(" ");
			else                                    // change alphabet
				printf("%c", cry[str[i] - 'A']);
		printf("\n");
	}
	return 0;
}