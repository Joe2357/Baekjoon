#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX (int)(2e4)
#define MAX_LEN 50
const int BIGGER = 1;
const int SMALLER = -1;
const int EQUAL = 0;

typedef struct String {
	char str[MAX_LEN + 1];
	int len;
} STRING;

STRING arr[MAX_IDX];
int n;

int string_compare(char* a, char* b) {
	int ret = EQUAL;

	for (int i = 0; i <= MAX_LEN; ++i) {
		if (a[i] > b[i]) {
			ret = BIGGER;
			break;
		} else if (a[i] < b[i]) {
			ret = SMALLER;
			break;
		} else if (a[i] == '\0' && b[i] == '\0') {
			break;
		}
	}

	return ret;
}

int string_asc(const void* a, const void* b) {
	STRING* sa = (STRING*)a;
	STRING* sb = (STRING*)b;

	if (sa->len > sb->len) {
		return BIGGER;
	} else if (sa->len < sb->len) {
		return SMALLER;
	} else {
		return string_compare(sa->str, sb->str);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i].str);
		for (arr[i].len = 0; arr[i].str[arr[i].len] != '\0'; ++arr[i].len) {
		}
	}
	qsort(arr, n, sizeof(STRING), string_asc);

	printf("%s\n", arr[0].str);
	for (int i = 1; i < n; ++i) {
		if (string_compare(arr[i - 1].str, arr[i].str) != EQUAL) {
			printf("%s\n", arr[i].str);
		}
	}
	return 0;
}