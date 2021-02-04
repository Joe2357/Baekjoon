#include <stdio.h>

#define MAX_INDEX 100

int alphabet[26] = { 0 };
char result[MAX_INDEX + 1];
int len;

void backtrack(int used) {
	if (used == len) {
		printf("%s\n", result);
		return;
	}

	for (int i = 0; i < 26; ++i) {
		if (alphabet[i]) {
			--alphabet[i];
			result[used] = i + 'a';
			backtrack(used + 1);
			++alphabet[i];
		}
	}
	return;
}

int main() {
	int t, i;
	scanf("%d", &t);
	while (t--) {
		char str[MAX_INDEX + 1];
		scanf("%s", str);

		for (int i = 0; i < 26; ++i)
			alphabet[i] = 0;

		for (i = 0; str[i]; ++i)
			++alphabet[str[i] - 'a'];
		len = i;
		result[len] = '\0';

		backtrack(0);
	}
	return 0;
}