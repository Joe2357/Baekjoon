#include <stdio.h>

#define MAX_LEN 100

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);
	int result = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		result += (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u');
	}
	printf("%d", result);
	return 0;
}