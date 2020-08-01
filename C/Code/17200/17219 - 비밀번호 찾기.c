#include <stdio.h>
#include <string.h>

typedef struct Site {
	char name[21],
		pwd[21];
} ST;

int cmp(ST *a, ST *b) {
	return strcmp(a->name, b->name);
}

int main() {
	int n, m;
	ST arr[100000] = { 0 };
	char tstr[21];
	// input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", tstr);
		strcpy(arr[i].name, tstr);
		scanf("%s", tstr);
		strcpy(arr[i].pwd, tstr);
	}
	// sort
	qsort(arr, n, sizeof(ST), cmp);
	for (; m; m--) {
		scanf("%s", tstr);
		int start = 0, end = n;
		while (1) { // binary search
			int mid = (start + end) / 2,
				temp = strcmp(tstr, arr[mid].name);
			if (!temp) {
				printf("%s\n", arr[mid].pwd);
				break;
			}
			else if (temp < 0)
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
	return 0;
}