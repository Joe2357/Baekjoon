#include <stdio.h>

int main() {
	char str[101];
	int arr[26] = { 0 };
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
		arr[str[i] - 97]++; // index count
	for (int i = 0; i < 26; i++)
		printf("%d ", arr[i]);
	return 0;
}