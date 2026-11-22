#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 256

char str[MAX_LEN + 1];

int main() {
	int ans = 0;
	while (true) {
		gets(str);
		if (str[0] == '#') {
			break;
		}

		ans = 0;

		for (int i = 0; str[i] != '\0'; ++i) {
			ans += (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u');
			ans += (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U');
		}
		printf("%d\n", ans);
	}
	return 0;
}