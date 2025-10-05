#include <stdio.h>

#define MAX_LEN (int)(1e6)
char str[MAX_LEN + 1];
const char SPACE = ' ';

int main() {
	gets(str);

	int result = 0;
	for (int i = (str[0] == SPACE); str[i] != '\0'; ++i) {
		if (str[i] != SPACE) {
			result += 1;
			while (str[i + 1] != SPACE && str[i + 1] != '\0') { // 단어의 끝까지 이동
				++i;
			}
		}
	}
	printf("%d", result);
	return 0;
}