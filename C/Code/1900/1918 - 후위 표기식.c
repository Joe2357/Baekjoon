#include <stdio.h>

int main() {
	char str[101], result[101] = { 0 }, stack[101] = { 0 };
	int rear = -1, i = 0, r = 0;
	scanf("%s", str);
	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z')		// must push alphabet to result
			result[r++] = str[i];
		else if (str[i] == '(')					// must push ( to stack
			stack[++rear] = str[i];
		else if (str[i] == ')') {				// pop all value until (
			while (stack[rear] != '(')
				result[r++] = stack[rear--];
			rear--;								// pop (
		}
		else if ((stack[rear] == '*' || stack[rear] == '/') || ((stack[rear] == '+' || stack[rear] == '-') && (str[i] == '+' || str[i] == '-')))	// push result if condition is satisfied
			result[r++] = stack[rear--], i--;
		else							// just push to stack
			stack[++rear] = str[i];
		i++;
	}
	while (rear != -1)					// pop all value of stack
		result[r++] = stack[rear--];
	printf("%s", result);		// print result
	return 0;
}