#include <stdio.h>
#include <string.h>

int main() {
	char str[101];
	scanf("%s", str);
	printf("%d", strlen(str));  // using strlen() function
	return 0;
}

void getLength(char *str) {		// not using strlen() function
	int i = 0;
	for (; str[i]; i++);
	printf("%d", i);
	return;
}