#include <stdio.h>
#define MAX_INDEX 250 + 2 + 1

int main() {
	char str[MAX_INDEX];

	while (1) {
		int retval = 0;
		gets(str);

		if (str[0] == '#')
			break;

		for (int i = 2; str[i]; i++)
			retval += (str[0] == str[i] || str[0] == str[i] + 32);

		printf("%c %d\n", str[0], retval);
	}

	return 0;
}