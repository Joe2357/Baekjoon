#include <stdio.h>

int main() {
	int n, word = 0;
	for (scanf("%d", &n); n; n--) {
		char str[200];
		scanf("%s", str);							
		int arr[26] = { 0 }, j = 0;
		char temp = '\0';
		while (1) {
			int temp2 = str[j];
			temp2 -= 97;
			if (arr[temp2] && str[j] != temp)	// already appeared & not same with previous target
				break;							// target word is not group word
			else if (!str[j]) {					// target is group word
				word++;
				break;
			}
			arr[temp2] = 1;
			temp = str[j++];
		}
	}
	printf("%d", word);
	return 0;
}