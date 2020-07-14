#include <stdio.h>

int main() {
	int result = 0;
	char str[101];
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
		result += (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u');
	printf("%d", result);
	return 0;
}