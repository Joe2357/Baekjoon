#include <stdio.h>
#include <string.h>

int main() {
	// init
	char str[500] = { 0 };

	// loop unless input is "END"
	while (1) {
		gets(str);
		if (!strcmp(str, "END"))
			break;
		// verse print
		for (int i = 0; str[i]; i++)
			printf("%c", str[strlen(str) - i - 1]);
		printf("\n");
	}
	return 0;
}