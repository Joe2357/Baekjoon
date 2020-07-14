#include <stdio.h>

int main() {
	char str[51];
	scanf("%s", str);
	int result = 10;
	for (int i = 1; str[i]; i++)
		result += 5 + 5 * (str[i] != str[i - 1]); // if same, +5 else +10
	printf("%d", result);
	return 0;
}