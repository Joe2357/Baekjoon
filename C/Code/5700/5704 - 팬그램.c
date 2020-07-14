#include <stdio.h>
#include <string.h>

int main() {
	char str[201];
	for (gets(str); strcmp(str, "*"); gets(str)) { // while not "*"
		int arr[26] = { 0 }, sum = 0;
		for (int i = 0; str[i]; i++)
			if (str[i] != ' ')
				arr[str[i] - 'a'] = 1; // count alphabet
		for (int i = 0; i < 26; i++)
			sum += arr[i];
		if (sum == 26)
			printf("Y\n"); // if all alphabet were used
		else
			printf("N\n");
	}
}