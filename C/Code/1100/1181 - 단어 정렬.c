#include <stdio.h>
#include <string.h>		// using strcmp, strlen, strcpy function

int cmp(char* a, char* b) {		// compare function ( Quicksort )
	return strlen(a) - strlen(b) + strcmp(a, b) * (strlen(a) == strlen(b));
}

int main(n) {
	scanf("%d", &n);
	char arr[20000][51];
	for (int i = 0; i < n; i++)				// input all string
		scanf("%s", arr[i]);
	qsort(arr, n, sizeof(arr[0]), cmp);		// Quicksort
	for (int i = 0; i < n; i++)
		if (strcmp(arr[i - 1], arr[i]))		// overlapped
			printf("%s\n", arr[i]);
	return 0;
}