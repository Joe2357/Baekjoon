#include <stdio.h>

int main(a, b, c) {
	scanf("%d %d %d", &a, &b, &c);
	char temp1, temp2;
	if (a + b == c)
		temp1 = '+', temp2 = '='; // a + b = c
	else if (a - b == c)
		temp1 = '-', temp2 = '='; // a - b = c
	else if (a * b == c)
		temp1 = '*', temp2 = '='; // a * b = c
	else if (a / b == c)
		temp1 = '/', temp2 = '='; // a / b = c
	else if (b + c == a)
		temp1 = '=', temp2 = '+'; // a = b + c
	else if (b - c == a)
		temp1 = '=', temp2 = '-'; // a = b - c
	else if (b * c == a)
		temp1 = '=', temp2 = '*'; // a = b * c
	else if (b / c == a)
		temp1 = '=', temp2 = '/'; // a = b / c
	printf("%d%c%d%c%d", a, temp1, b, temp2, c);
	return 0;
}