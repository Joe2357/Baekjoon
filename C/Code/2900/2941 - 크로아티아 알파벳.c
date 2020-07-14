#include <stdio.h>

int main() {
	char str[200];
	gets(str);  // get string
	int word = 0;
	for (int i = 0; str[i]; i++) {   // while end of string
		switch (str[i]) {
			case 'c':
				if (str[i + 1] == '=' || str[i + 1] == '-') {
					word++;
					i++;
				}
				else
					word++;
				break;
			case 'd':
				if (str[i + 1] == 'z' && str[i + 2] == '=') {
					word++;
					i += 2;
				}
				else if (str[i + 1] == '-') {
					word++;
					i++;
				}
				else
					word++;
				break;
			case 'l':
				if (str[i + 1] == 'j') {
					word++;
					i++;
				}
				else
					word++;
				break;
			case 'n':
				if (str[i + 1] == 'j') {
					word++;
					i++;
				}
				else
					word++;
				break;
			case 's':
				if (str[i + 1] == '=') {
					word++;
					i++;
				}
				else
					word++;
				break;
			case 'z':
				if (str[i + 1] == '=') {
					word++;
					i++;
				}
				else
					word++;
				break;
			default:
				word++;
				break;
		}
	}
	printf("%d", word);
	return 0;
}