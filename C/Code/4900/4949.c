#include <stdio.h>

int main() {
	// loop while end process
	while (1) {
		// input
		char str[101];
		gets(str);

		// end program
		if (str[0] == '.' && !str[1])
			break;

		char stack[101] = {0};
		int rear = 0, result = 0;

		// string compare while end of string
		for (int i = 0; str[i]; i++) {
			switch (str[i]) {
				case '(':
					stack[rear++] = '(';
					break;
				case '[':
					stack[rear++] = '[';
					break;
				case ')':
					if (!rear)
						result = 1;
					else if (stack[--rear] != '(')
						result = 1;
					else
						;
					break;
				case ']':
					if (!rear)
						result = 1;
					else if (stack[--rear] != '[')
						result = 1;
					else
						;
					break;
				default:
					break;
			}
		}
		if (result || rear)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}