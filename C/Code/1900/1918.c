#include <stdio.h>

int main() {
	char str[101], result[101] = {0}, stack[101] = {0};
	int rear = -1, i = 0, r = 0;
	scanf("%s", str);
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			result[r++] = str[i];
		else if (str[i] == '(')
			stack[++rear] = str[i];
		else if (str[i] == ')') {
			while (stack[rear] != '(')
				result[r++] = stack[rear--];
			rear--;
		} else if (stack[rear] == '*' || stack[rear] == '/') {
			result[r++] = stack[rear--];
			i--;
		} else if ((stack[rear] == '+' || stack[rear] == '-') && (str[i] == '+' || str[i] == '-')) {
			result[r++] = stack[rear--];
			i--;
		} else
			stack[++rear] = str[i];
		i++;
	}
	while (rear != -1)
		result[r++] = stack[rear--];
	printf("%s", result);
	return 0;
}