#include <stdio.h>

int main() {
	char str[1000001];
	scanf("%s", str);
	int arr[26] = { 0 }, max = 0;
	for (int i = 0; str[i]; i++) {
		int temp = str[i] - 65;				// 'A' ~ 'Z' , 'a' ~ 'z'
		if (temp > 30)						// 'a' ~ 'z'
			temp -= 32;						// change 'a' ~ 'z' to 'A' ~ 'Z'
		arr[temp]++;						// count alphabet
		if (max < arr[temp])				// finding maximun amount of alphabet
			max = arr[temp];
	}
	char temp = '\0';						// reset
	for (int i = 0; i < 26; i++)
		if (arr[i] == max)
			if (temp) {						// they are corrupted
				printf("?");
				return 0;
			}
			else							// didn't corrupt
				temp = i + 65;
	printf("%c", temp);
	return 0;
}