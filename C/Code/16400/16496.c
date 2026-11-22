#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define M 1000

char arr[M][11];
int n;

int cmp(char* a, char* b) {
	int al = 0, bl = 0;
	while (a[al] != '\0') {
		++al;
	}
	while (b[bl] != '\0') {
		++bl;
	}

	int x = 0, y = 0, z = al + bl;
	while (x < z) {
		char t1, t2;
		if (x >= al) {
			t1 = b[x - al];
		} else {
			t1 = a[x];
		}
		if (y >= bl) {
			t2 = a[y - bl];
		} else {
			t2 = b[y];
		}

		if (t1 > t2) {
			return -1;
		} else if (t1 < t2) {
			return 1;
		}
		++x, ++y;
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", arr[i]);
	}

	/* sort */
	qsort(arr, n, sizeof(char[11]), cmp);
	/* --- */

	if (arr[0][0] == '0') {
		printf("0");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		printf("%s", arr[i]);
	}
	return 0;
}