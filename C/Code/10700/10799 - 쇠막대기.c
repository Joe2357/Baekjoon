#include <stdio.h>

int main() {
	char str[100001];
	scanf("%s", str);
	int sum = 0, stick = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] == '(' && str[i + 1] == ')')
			sum += stick, // add to value
			i++;
		else if (str[i] == '(' && str[i + 1] != ')')
			stick++, // can make 1 more stick
			sum++;
		else // 1 stick end
			stick--;
	printf("%d", sum);
	return 0;
}