#include <stdio.h>

int main() {
	int arr[26];
	for (int i = 0; i < 26; i++)
		arr[i] = -1;
	char str[100];
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		int t = str[i] - 97;
		if (arr[t] == -1) // only check first occur
			arr[t] = i;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);
	return 0;
}