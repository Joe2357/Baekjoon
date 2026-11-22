#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define MAX_IDX (int)(1e5)

typedef struct Town {
	int x;
	int a;
} Town;

Town town[MAX_IDX];
int n;
ll sum_a = 0LL;

int asc(const void* a, const void* b) {
	Town* t1 = (Town*)a;
	Town* t2 = (Town*)b;
	if (t1->x > t2->x) {
		return 1;
	} else if (t1->x < t2->x) {
		return -1;
	} else {
		return 0;
	}
}

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &town[i].x, &town[i].a);
		sum_a += town[i].a;
	}
	return;
}

int main() {
	read_input();
	qsort(town, n, sizeof(Town), asc);

	ll temp = 0LL;
	for (int i = 0; i < n; ++i) {
		temp += town[i].a;
		if (temp >= (sum_a + 1LL) / 2) {
			printf("%d", town[i].x);
			break;
		}
	}
	return 0;
}