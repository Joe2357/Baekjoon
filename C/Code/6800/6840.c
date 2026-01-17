#include <stdio.h>
#include <stdlib.h>

int asc(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return 1;
	} else if (*(int*)a < *(int*)b) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int bowl[3];
	scanf("%d %d %d", bowl, bowl + 1, bowl + 2);
	qsort(bowl, 3, sizeof(int), asc);
	printf("%d", bowl[1]);
	return 0;
}