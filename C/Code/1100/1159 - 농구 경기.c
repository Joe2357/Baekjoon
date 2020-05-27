#include <stdio.h>

int main() {
	int n, arr[26] = { 0 }, boolean = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char name[35];
		scanf("%s", name);
		arr[name[0] - 97]++;				// count first letter
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {					// apeear at least 5 times
			printf("%c", i + 97);
			boolean = 0;					// we found whether arr[i] >= 5
		}
	}
	if (boolean)							// if we coundn't find
		printf("PREDAJA");
	return 0;
}