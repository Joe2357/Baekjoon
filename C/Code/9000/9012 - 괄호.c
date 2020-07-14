#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		char str[51];
		scanf("%s", str);
		int result = 0;
		for (int i = 0; str[i]; i++) {
			if (str[i] == ')') {
				result--; // pop
				if (result < 0) // not VPS
					break;
			}
			else if (str[i] == '(')
				result++; // stack push
		}
		if (!result)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}