#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX (int)(1e4)

typedef struct Pond {
	int left, right;
} Pond;

Pond ponds[MAX_IDX];
int n, l;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int left_asc(const void* a, const void* b) {
	Pond* x = (Pond*)a;
	Pond* y = (Pond*)b;
	return x->left > y->left;
}

void read_input() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &ponds[i].left, &ponds[i].right);
	}
	qsort(ponds, n, sizeof(Pond), left_asc);
	return;
}

int main() {
	read_input();

	int ret = 0, current_start_point = -1;
	for (int i = 0; i < n; ++i) {
		if (current_start_point < ponds[i].right) {
			int start_pos = max(current_start_point, ponds[i].left);
			int dist = (ponds[i].right - start_pos);
			int needs = dist / l + (dist % l != 0);
			ret += needs, current_start_point = start_pos + (needs * l);
		}
	}

	printf("%d", ret);
	return 0;
}