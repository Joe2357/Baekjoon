#include <stdio.h>

int main(t) {
	scanf("%d", &t);
	for (int i = 0; i <= t; i++) {
		char str[51];
		gets(str);
		if (i)
			printf("%d. %s\n", i, str); // first str : bufferRead, so ignore
	}
	return 0;
}