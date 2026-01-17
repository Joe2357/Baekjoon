#include <stdio.h>

#define MAX_LEN (int)(1e5)
const char SPACE = ' ';

char str[MAX_LEN + 1];

void changeCharacter(int x) {
	switch (str[x]) {
		case 'A': {
			break;
		}
		case 'B': {
			str[x] = 'V';
			break;
		}
		case 'C': {
			str[x] = 'X';
			break;
		}
		case 'D': {
			str[x] = 'S';
			break;
		}
		case 'E': {
			str[x] = 'W';
			break;
		}
		case 'F': {
			str[x] = 'D';
			break;
		}
		case 'G': {
			str[x] = 'F';
			break;
		}
		case 'H': {
			str[x] = 'G';
			break;
		}
		case 'I': {
			str[x] = 'U';
			break;
		}
		case 'J': {
			str[x] = 'H';
			break;
		}
		case 'K': {
			str[x] = 'J';
			break;
		}
		case 'L': {
			str[x] = 'K';
			break;
		}
		case 'M': {
			str[x] = 'N';
			break;
		}
		case 'N': {
			str[x] = 'B';
			break;
		}
		case 'O': {
			str[x] = 'I';
			break;
		}
		case 'P': {
			str[x] = 'O';
			break;
		}
		case 'Q': {
			break;
		}
		case 'R': {
			str[x] = 'E';
			break;
		}
		case 'S': {
			str[x] = 'A';
			break;
		}
		case 'T': {
			str[x] = 'R';
			break;
		}
		case 'U': {
			str[x] = 'Y';
			break;
		}
		case 'V': {
			str[x] = 'C';
			break;
		}
		case 'W': {
			str[x] = 'Q';
			break;
		}
		case 'X': {
			str[x] = 'Z';
			break;
		}
		case 'Y': {
			str[x] = 'T';
			break;
		}
		case 'Z': {
			break;
		}
		case '`': {
			break;
		}
		case '1': {
			str[x] = '`';
			break;
		}
		case '2': {
			str[x] = '1';
			break;
		}
		case '3': {
			str[x] = '2';
			break;
		}
		case '4': {
			str[x] = '3';
			break;
		}
		case '5': {
			str[x] = '4';
			break;
		}
		case '6': {
			str[x] = '5';
			break;
		}
		case '7': {
			str[x] = '6';
			break;
		}
		case '8': {
			str[x] = '7';
			break;
		}
		case '9': {
			str[x] = '8';
			break;
		}
		case '0': {
			str[x] = '9';
			break;
		}
		case '-': {
			str[x] = '0';
			break;
		}
		case '=': {
			str[x] = '-';
			break;
		}
		case '[': {
			str[x] = 'P';
			break;
		}
		case ']': {
			str[x] = '[';
			break;
		}
		case '\\': {
			str[x] = ']';
			break;
		}
		case ';': {
			str[x] = 'L';
			break;
		}
		case '\'': {
			str[x] = ';';
			break;
		}
		case ',': {
			str[x] = 'M';
			break;
		}
		case '.': {
			str[x] = ',';
			break;
		}
		case '/': {
			str[x] = '.';
			break;
		}
	}
}

int main() {
	while (gets(str) != NULL) {
		for (int i = 0; str[i] != '\0'; ++i) {
			if (str[i] != SPACE) {
				changeCharacter(i);
			}
		}
		printf("%s\n", str);
	}
	return 0;
}