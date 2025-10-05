#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 250
const int target = 0;

char str[MAX_LEN + 1];

int main() {
	while (true) {
		int result = 0;
		gets(str);

		if (str[target] == '#') {
			break;
		}

		for (int i = 2; str[i] != '\0'; i++) {
			if ('a' <= str[i] && str[i] <= 'z') {
				result += (str[i] == str[target]);
			} else {
				result += (str[i] - 'A' + 'a' == str[target]);
			}
		}

		printf("%c %d\n", str[target], result);
	}

	return 0;
}