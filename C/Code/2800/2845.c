#include <stdio.h>

#define MAX_IDX 5

int main() {
	int l, p;
	scanf("%d %d", &l, &p);

	for (int i = 0; i < MAX_IDX; ++i) {
		int x;
		scanf("%d", &x);
		printf("%d ", x - (l * p));
	}
	return 0;
}