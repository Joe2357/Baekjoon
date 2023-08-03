#include <stdio.h>

typedef struct Node {
	char start;
	char end;
	int score;
} ND;

#define MAX_IDX 16
ND arr[MAX_IDX];
int n;
int result = 0;

#define MAX_VOWEL 5
#define MAX_ALPHABET 26

int len(char* s) {
	int t;
	for (t = 0; s[t] != '\0'; ++t) {
	}
	return t;
}
int getVowelIndex(char x) {
	switch (x) {
		case 'A': {
			return 0;
		}
		case 'E': {
			return 1;
		}
		case 'I': {
			return 2;
		}
		case 'O': {
			return 3;
		}
		case 'U': {
			return 4;
		}
	}
}

#define max(a, b) (((a) > (b)) ? (a) : (b))

#define NOTVISIT -1
int dp[MAX_VOWEL][1 << MAX_IDX];

#define MAX_LEN 100
void read_input() {
	scanf("%d", &n);
	char str[MAX_LEN + 1];
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);

		int j = len(str);
		arr[i] = (ND){str[0], str[j - 1], j};
	}
	return;
}

int search(char e, int v, int s) {
	if (dp[getVowelIndex(e)][v] != NOTVISIT) {
		return dp[getVowelIndex(e)][v];
	}

	dp[getVowelIndex(e)][v] = s;
	result = max(result, s);
	for (int i = 0; i < n; ++i) {
		if ((arr[i].start == e) && ((v & (1 << i)) == 0)) {
			search(arr[i].end, (v | (1 << i)), s + arr[i].score);
		}
	}
	return dp[getVowelIndex(e)][v];
}

char vowel[MAX_VOWEL] = {'A', 'E', 'I', 'O', 'U'};
void solve() {
	for (int i = 0; i < MAX_VOWEL; ++i) {
		search(vowel[i], 0, 0);
	}
	return;
}

int main() {
	read_input();

	for (int i = 0; i < MAX_VOWEL; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			dp[i][j] = NOTVISIT;
		}
	}
	solve();

	printf("%d", result);
	return 0;
}