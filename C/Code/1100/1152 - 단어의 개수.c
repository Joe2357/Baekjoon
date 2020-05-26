#include <stdio.h>

int main() {
	char str[2000000];
	gets(str);
	if (str[0] == ' ') {								// first space removing
		int i = 0;
		while (str[i] != '\0') {
			str[i] = str[i + 1];
			i++;
		}
	}
	if (str[0] == '\0') {								// case : No string
		printf("0");
		return 0;
	}
	else {
		int i = 0, count = 1;
		while (str[i] != '\0') {
			if (str[i] == ' ' && str[i + 1] != '\0')
				count++;
			i++;
		}
		printf("%d", count);
	}
	return 0;
}