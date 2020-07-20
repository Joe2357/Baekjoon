#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct School {
	char name[25];
	int drink;
};
typedef struct School SC;

int cmp(SC *a, SC *b) {
	return b->drink - a->drink;
}

int main(t) {
	// loop testcase
	for (scanf("%d", &t); t; t--) {
		// init
		SC arr[100];
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char str[25];
			scanf("%s %d", str, &arr[i].drink);
			strcpy(arr[i].name, str);
		}

		// desending order sort
		qsort(arr, n, sizeof(arr[0]), cmp);

		// print result
		printf("%s\n", arr[0].name);
	}
	return 0;
}