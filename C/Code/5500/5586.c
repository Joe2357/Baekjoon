#include <stdio.h>

#define MAX_LEN 10000

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);

	int joi = 0, ioi = 0;
	for (int i = 0; str[i + 2] != '\0'; ++i) {
		switch (str[i]) {
			case 'J': {
				joi += (str[i + 1] == 'O' && str[i + 2] == 'I');
				break;
			}
			case 'I': {
				ioi += (str[i + 1] == 'O' && str[i + 2] == 'I');
				break;
			}
			default: {
				break;
			}
		}
	}

	printf("%d\n%d", joi, ioi);
	return 0;
}