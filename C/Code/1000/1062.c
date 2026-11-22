#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 50
#define MAX_LEN 16
const int MINIMUM_ALPHABET = 5;
#define ALPHABET_LEN 26

int n, k;
int word[MAX_IDX];
int result;

char standard[ALPHABET_LEN + 1];

#define max(a, b) (((a) > (b)) ? (a) : (b))

void essential_alphabet_init() {
	char s[10] = "antic";
	for (int i = 0; s[i] != '\0'; ++i) {
		standard[s[i] - 'a'] = true;
	}
	return;
}

void backtrack(int num, int cnt, int pos) {
	if (cnt == k) {
		int temp = 0;
		for (int i = 0; i < n; ++i) {
			if ((num & word[i]) == word[i]) {
				++temp;
			}
		}
		result = max(result, temp);
		return;
	}

	for (int i = pos; i < ALPHABET_LEN; ++i) {
		if (standard[i] == false) {
			backtrack(num + (1 << i), cnt + 1, i + 1);
		}
	}
	return;
}

int main() {
	essential_alphabet_init();

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		char str[MAX_LEN];
		scanf("%s", str);
		for (int j = 0; str[j] != '\0'; ++j) {
			word[i] |= (1 << (str[j] - 'a'));
		}
	}

	if (k < MINIMUM_ALPHABET) {
		printf("0");
		return 0;
	} else {
		int std = 0;
		for (int i = 0; i < ALPHABET_LEN; ++i) {
			if (standard[i] == true) {
				std += (1 << i);
			}
		}

		backtrack(std, MINIMUM_ALPHABET, 0);
	}

	printf("%d", result);
	return 0;
}