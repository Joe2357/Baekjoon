#include <stdio.h>

typedef char boolean;
#define True 1
#define False 0

typedef struct Node {
	int v;
	int c;
} ND;

int l, c;
boolean alpha[26] = { False };
boolean vowel[26] = { False };
#define M_L 15
char result[M_L + 1];

void init() {
	vowel['a' - 'a'] = vowel['e' - 'a'] = vowel['i' - 'a'] = vowel['o' - 'a'] = vowel['u' - 'a'] = True;
	return;
}

void backtrack(int n, char now, ND used) {
	if (n == l) {
		if (used.v >= 1 && used.c >= 2)
			printf("%s\n", result);
		return;
	}

	for (char t = now + 1; t <= 'z'; ++t) {
		if (alpha[t - 'a']) {
			result[n] = t;
			if (vowel[t - 'a'])
				++used.v;
			else
				++used.c;
			backtrack(n + 1, t, used);
			if (vowel[t - 'a'])
				--used.v;
			else
				--used.c;
		}
	}

	return;
}

int main() {
	init();

	scanf("%d %d", &l, &c);
	result[l] = '\0';
	for (; c; c--) {
		char str[2];
		scanf("%s", str);
		alpha[str[0] - 'a'] = True;
	}

	backtrack(0, 'a' - 1, (ND) { 0, 0 });

	return 0;
}