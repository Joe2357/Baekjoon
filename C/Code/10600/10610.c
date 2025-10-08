#include <stdio.h>

int main() {
	char str[100001];
	int arr[10] = {0}, i = 0, sum = 0;
	scanf("%s", str);
	while (str[i])
		arr[str[i] - '0']++, sum += str[i] - '0', i++;
	if (!arr[0] || sum % 3)
		printf("-1");
	else
		for (i = 10; i; i--)
			for (; arr[i - 1]; arr[i - 1]--)
				printf("%d", i - 1);
	return 0;
}