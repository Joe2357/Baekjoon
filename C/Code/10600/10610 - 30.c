#include <stdio.h>

int main() {
	char str[100001];
	int arr[10] = { 0 }, sum = 0;
	scanf("%s", str);
	for (int i = 0; str[i]; i++) // count all digits
		arr[str[i] - '0']++, sum += str[i] - '0';
	if (!arr[0] || sum % 3) // conditions to be multiple of 30
		printf("-1");
	else // print the biggest number
		for (int i = 10; i; i--)
			for (; arr[i - 1]; arr[i - 1]--)
				printf("%d", i - 1);
	return 0;
}