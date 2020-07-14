#include <stdio.h>

int main() {
	char str[101];
	scanf("%s", str);
	int result = 0;
	for (int i = 0; str[i]; i++)
		result += (str[i] == ','); // assume integers are split by ','
	printf("%d", ++result);
	return 0;
}