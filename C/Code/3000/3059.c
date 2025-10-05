#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int arr[26] = {0}, sum = 0;
		for (int i = 'A'; i <= 'Z'; i++)
			sum += i;
		char str[1001];
		scanf("%s", str);
		for (int i = 0; str[i]; i++)
			sum -= str[i] * (!arr[str[i] - 'A']), arr[str[i] - 'A']++;
		printf("%d\n", sum);
	}
	return 0;
}