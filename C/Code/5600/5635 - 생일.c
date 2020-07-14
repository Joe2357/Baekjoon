#include <stdio.h>
#include <string.h>

typedef struct Student {
	char name[20];
	int year, month, day;
} ST;

int cmp(ST *a, ST *b) {
	int y = a->year - b->year,
		m = a->month - b->month,
		d = a->day - b->day;
	return y * 32 * 13 + m * 32 + d;
}

int main(n) {
	ST arr[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[20];
		scanf("%s %d %d %d", str, &arr[i].day, &arr[i].month, &arr[i].year);
		strcpy(arr[i].name, str);
	}
	qsort(arr, n, sizeof(ST), cmp);
	printf("%s\n%s", arr[n - 1].name, arr[0].name);
	return 0;
}