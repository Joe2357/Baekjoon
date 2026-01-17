#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN (int)(2e5)
#define ALPHABET 26

char str[MAX_LEN + 1];
int n;
int left_use[ALPHABET], right_use[ALPHABET];

int main() {
	scanf("%d %s", &n, str);

	for (int i = 0; i < n / 2; ++i) {
		left_use[str[i] - 'a'] += 1;
		right_use[str[n - 1 - i] - 'a'] += 1;
	}

	bool is_palindrome_possible = true;
	for (int i = 0; i < ALPHABET; ++i) {
		is_palindrome_possible &= ((left_use[i] + right_use[i]) % 2 == 0);
	}

	printf("%s", (is_palindrome_possible == true ? "Yes\n" : "No\n"));
	return 0;
}