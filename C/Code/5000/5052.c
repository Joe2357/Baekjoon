#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 10000
#define MAX_LEN 10

int n;
char arr[MAX_IDX][MAX_LEN + 1];
char printTemplate[2][4] = {"NO", "YES"};

int cmp(char* a, char* b) {
	for (int i = 0; a[i] != '\0'; ++i) {
		if (a[i] != b[i]) {
			return a[i] > b[i];
		}
	}

	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", arr[i]);
		}
		qsort(arr, n, sizeof(char[MAX_LEN + 1]), cmp);

		bool isConsistent = true;
		for (int i = 1; i < n; ++i) {
			bool isNotSame = false;
			for (int j = 0; arr[i - 1][j] != '\0'; ++j) {
				if (arr[i - 1][j] != arr[i][j]) {
					isNotSame = true;
					break;
				}
			}

			if (isNotSame == false) {
				isConsistent = false;
			}

			if (isConsistent == false) {
				break;
			}
		}

		printf("%s\n", printTemplate[isConsistent]);
	}
	return 0;
}