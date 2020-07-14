#include <stdio.h>

// integer descending order
int compare(int *a, int *b) {
	return *b - *a;
}

int main() {
	int w[10], k[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", w + i);
	qsort(w, 10, sizeof(w[0]), compare);
	for (int i = 0; i < 10; i++)
		scanf("%d", k + i);
	qsort(k, 10, sizeof(k[0]), compare);
	printf("%d %d", w[0] + w[1] + w[2], k[0] + k[1] + k[2]);
	return 0;
}