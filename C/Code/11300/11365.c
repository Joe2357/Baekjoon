#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 500

char str[MAX_LEN + 1];

bool isExitCode() {
	return str[0] == 'E' && str[1] == 'N' && str[2] == 'D' && str[3] == '\0';
}

int main() {
	while (true) {
		gets(str);
		if (isExitCode() == true) {
			break;
		} else {
			int length = 0;
			while (str[length] != '\0') {
				length++;
			}
			for (int j = length - 1; j >= 0; j--) {
				printf("%c", str[j]);
			}
			printf("\n");
		}
	}
	return 0;
}