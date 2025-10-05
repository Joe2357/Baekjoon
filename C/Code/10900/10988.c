#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 100

bool is_palindrome(const char* s) {
	int left = 0;
	int right = 0;
	while (s[right + 1] != '\0') {
		++right;
	}

	for (; left < right; ++left, --right) {
		if (s[left] != s[right]) {
			return false;
		}
	}
	return true;
}

int main() {
	char str[MAX_LEN + 1];
	scanf("%s", str);
	printf("%d", is_palindrome(str));
	return 0;
}