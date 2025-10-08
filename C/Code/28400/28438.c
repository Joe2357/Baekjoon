#include <stdio.h>

#define MAX_IDX (500000 + 1)

int n, m, q;
int row[MAX_IDX];
int col[MAX_IDX];

int main() {
	scanf("%d %d %d", &n, &m, &q);
	while (q--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		switch (a) {
			case 1: {
				row[b] += c;
				break;
			}
			case 2: {
				col[b] += c;
				break;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d ", row[i] + col[j]);
		}
		printf("\n");
	}
}