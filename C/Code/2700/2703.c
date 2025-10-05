#include <stdio.h>

#define MAX_LEN 100
#define LENGTH_OF_ALPHABET 26
const char SPACE = ' ';

char str[MAX_LEN + 1];
char crypto_table[LENGTH_OF_ALPHABET + 1];

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		getchar(); // 입력 버퍼 처리
		gets(str);
		scanf("%s", crypto_table);

		for (int i = 0; str[i] != '\0'; ++i) {
			char c = str[i];
			if ('A' <= str[i] && str[i] <= 'Z') {
				c = crypto_table[c - 'A'];
			}
			printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}