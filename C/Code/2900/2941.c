#include <stdio.h>

#define MAX_LEN 100

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);
	int ret = 0;

	for (int i = 0; str[i] != '\0'; ++i) {
		ret += 1;
		switch (str[i]) {
			case 'c': {
				i += (str[i + 1] == '=' || str[i + 1] == '-');
				break;
			}
			case 'd': {
				i += (str[i + 1] == '-');

				i += 2 * (str[i + 1] == 'z' && str[i + 2] == '=');
				break;
			}
			case 'l':
			case 'n': {
				i += (str[i + 1] == 'j');
				break;
			}
			case 's':
			case 'z': {
				i += (str[i + 1] == '=');
				break;
			}
			default: {
				break;
			}
		}
	}
	printf("%d", ret);
	return 0;
}