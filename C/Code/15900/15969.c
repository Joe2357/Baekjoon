#include <stdio.h>

#define MAX_IDX 1000

int happiness[MAX_IDX];
int n;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", happiness + i);
	}

	int min_h = happiness[0], max_h = happiness[0];
	for (int i = 0; i < n; ++i) {
		min_h = min(min_h, happiness[i]);
		max_h = max(max_h, happiness[i]);
	}
	printf("%d", max_h - min_h);
	return 0;
}