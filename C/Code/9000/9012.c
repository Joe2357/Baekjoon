#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int main() {
	int t;
	scanf("%d", &t);
	char str[51];

	while (t--) {
		int open = 0;
		bool isImpossibleState = false;
		scanf("%s", str);

		for (int i = 0; str[i] != '\0'; ++i) {
			switch (str[i]) {
				case '(': {
					++open;
					break;
				}
				case ')': {
					if (open > 0) {
						--open;
					} else {
						isImpossibleState = true;
						break;
					}
				}
			}

			if (isImpossibleState == true) {
				break;
			}
		}

		if (isImpossibleState == true) {
			printf("NO\n");
		} else if (open == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}