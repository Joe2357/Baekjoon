#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 2500

char document[MAX_LEN + 1];
char search[MAX_LEN + 1];

int main() {
	gets(document);
	gets(search);

	int document_len = 0, search_len = 0;
	for (; document[document_len] != '\0'; ++document_len) {
	}
	for (; search[search_len] != '\0'; ++search_len) {
	}

	int ret = 0;
	for (int i = 0; i <= document_len - search_len; ++i) {
		bool matched = true;
		for (int j = 0; j < search_len; ++j) {
			if (document[i + j] != search[j]) {
				matched = false;
				break;
			}
		}

		ret += matched;
		i += (matched * (search_len - 1));
	}
	printf("%d", ret);
	return 0;
}