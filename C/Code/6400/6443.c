#include <stdio.h>

#define MAX_LEN 20
int alpha['z' - 'a' + 1];
char input[MAX_LEN + 1];
char making[MAX_LEN + 1];
int len;

#define getIndex(x) ((x) - ('a'))

void init() {
	for (int i = 0; i < 26; ++i) {
		alpha[i] = 0;
	}
	return;
}
void alphabetCount() {
	for (len = 0; input[len] != '\0'; ++len) {
		++alpha[getIndex(input[len])];
	}
	making[len] = '\0';
	return;
}

void backtrack(int x) {
	if (x == len) {
		printf("%s\n", making);
		return;
	}

	for (int i = 0; i < 26; ++i) {
		if (alpha[i] > 0) {
			--alpha[i];
			making[x] = i + 'a';
			backtrack(x + 1);

			++alpha[i];
		}
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		init();
		scanf("%s", input);

		alphabetCount();
		backtrack(0);
	}
	return 0;
}