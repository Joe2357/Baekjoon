// can't open the problem#include <stdio.h>

int main(n, m) {
	char str[100][101] = { 0 }, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);
	for (int i = m; i; i--) {
		for (int j = 0; j < n; j++) {
			switch (str[j][i - 1]) {
				case '.':
				case 'O':
					c = str[j][i - 1];
					break;
				case '-':
					c = '|';
					break;
				case '|':
					c = '-';
					break;
				case '/':
					c = '\\';
					break;
				case '\\':
					c = '/';
					break;
				case '^':
					c = '<';
					break;
				case '<':
					c = 'v';
					break;
				case 'v':
					c = '>';
					break;
				case '>':
					c = '^';
					break;
			}
			str[j][i - 1] = '\0';
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}