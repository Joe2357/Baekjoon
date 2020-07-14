#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		char str[81];
		scanf("%s", str);
		int score = 0, O = 0;
		for (int i = 0; str[i]; i++)
			if (str[i] == 'O')
				O++, score += O; // continuous
			else
				O = 0; // reser
		printf("%d\n", score);
	}
	return 0;
}