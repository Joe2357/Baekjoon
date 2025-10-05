#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 1000

int score[MAX_STUDENT];
int n, k;

int desc(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return -1;
	} else if (*(int*)a < *(int*)b) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", score + i);
	}
	qsort(score, n, sizeof(int), desc);
	printf("%d", score[k - 1]);
	return 0;
}