#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 100
#define MAX_DICTIONARY 20
const int MAX_ALPHABET = 26;

char str[MAX_LEN + 1];
char dictionary[MAX_DICTIONARY][MAX_LEN + 1];
int n;

void shift_one() {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == 'z') {
			str[i] = 'a';
		} else {
			str[i] = str[i] + 1;
		}
	}
	return;
}

bool isSubString(const char* a, const char* b) {
	for (int i = 0; a[i] != '\0'; ++i) {
		int j = 0;
		while (a[i + j] != '\0' && b[j] != '\0' && a[i + j] == b[j]) {
			j++;
		}
		if (b[j] == '\0')
			return true;
	}
	return false;
}

bool is_in_dictionary() {
	for (int i = 0; i < n; ++i) {
		if (isSubString(str, dictionary[i]) == true) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%s", str);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", dictionary[i]);
	}

	for (int i = 0; i < MAX_ALPHABET; ++i) {
		shift_one();
		if (is_in_dictionary() == true) {
			printf("%s", str);
			break;
		}
	}
	return 0;
}