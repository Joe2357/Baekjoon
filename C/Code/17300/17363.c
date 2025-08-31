#include <stdio.h>

#define MAX_LEN 100

char str[MAX_LEN + 1][MAX_LEN + 1];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}

	for (int i = m-1; i >=0; --i) {
		for (int j = 0; j < n; j++) {
			char c;
			switch (str[j][i]) {
				case '.': {
					c = '.';
					break;
				}
				case 'O': {
					c = 'O';
					break;
				}
				case '-': {
					c = '|';
					break;
				}
				case '|': {
					c = '-';
					break;
				}
				case '/': {
					c = '\\';
					break;
				}
				case '\\': {
					c = '/';
					break;
				}
				case '^': {
					c = '<';
					break;
				}
				case '<': {
					c = 'v';
					break;
				}
				case 'v': {
					c = '>';
					break;
				}
				case '>': {
					c = '^';
					break;
				}
			}
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}