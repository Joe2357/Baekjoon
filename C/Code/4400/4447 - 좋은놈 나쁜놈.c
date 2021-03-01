#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	char str[26];
	gets(str);

	while (n--) {
		gets(str);
		printf("%s", str);
		int g = 0, b = 0;

		for (int i = 0; str[i]; ++i) {
			g += (str[i] == 'G' || str[i] == 'g');
			b += (str[i] == 'B' || str[i] == 'b');
		}

		if (g > b) {
			printf(" is GOOD\n");
		}
		else if (g < b) {
			printf(" is A BADDY\n");
		}
		else {
			printf(" is NEUTRAL\n");
		}
	}

	return 0;
}