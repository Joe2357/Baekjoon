#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 500

bool seat[MAX_IDX + 1 + 1];
int p, m;

void init() {
	for (int i = 0; i <= MAX_IDX; ++i) {
		seat[i] = false;
	}
	return;
}

int main() {
	int k;
	scanf("%d", &k);
	while (k--) {
		init();
		scanf("%d %d", &p, &m);

		int ret = 0;
		while (p--) {
			int x;
			scanf("%d", &x);

			if (seat[x] == false) {
				seat[x] = true;
			} else {
				ret += 1;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}