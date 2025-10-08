#include <stdio.h>

char str[51];
int minus;

int main() {
	scanf("%s", str);
	int i = 0, result = 0, temp = 0;
	while (str[i]) {
		switch (str[i]) {
			case '+':
			case '-':
				result += (minus) ? -temp : temp;
				temp = 0;
				minus += (str[i] == '-');
				break;
			default:
				temp = temp * 10 + str[i] - '0';
				break;
		}
		i++;
	}
	result += (minus) ? -temp : temp;
	printf("%d", result);
	return 0;
}