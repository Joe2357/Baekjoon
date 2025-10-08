#include <stdio.h>

int main() {
	char str[100001];
	scanf("%s", str);
	int i = 0, sum = 0, stick = 0;
	while (str[i] != '\0') {
		if (str[i] == '(' && str[i + 1] == ')') {
			sum += stick;
			i++;
		} else if (str[i] == '(' && str[i + 1] != ')') {
			stick++;
			sum++;
		} else
			stick--;
		i++;
	}
	printf("%d", sum);
	return 0;
}