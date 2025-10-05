#include <stdio.h>

#define MAX_LEN 80

char str[MAX_LEN + 1];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);

		int score = 0;
		int streak = 0;
		for (int i = 0; str[i] != '\0'; ++i) {
			switch (str[i]) {
				case 'O': {
					score += (++streak);
					break;
				}
				case 'X': {
					streak = 0;
					break;
				}
			}
		}
		printf("%d\n", score);
	}
	return 0;
}