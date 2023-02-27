#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	int pos;
	int cnt;
} ND;

#define MAX_IDX 100000
bool visit[MAX_IDX * 2 + 2];
ND q[MAX_IDX * 2 + 2];
int f, r;
int n, k;

int main() {
	scanf("%d %d", &n, &k);

	visit[n] = true;
	q[r++] = (ND){n, 0};

	while (f < r) {
		ND cur = q[f++];
		for (int i = cur.pos; i <= MAX_IDX * 2; i *= 2) {
			if (i == k) {
				printf("%d", cur.cnt);
				return 0;
			}

			if (i > 0 && visit[i - 1] == false) {
				visit[i - 1] = true;
				q[r++] = (ND){i - 1, cur.cnt + 1};
			}
			if (visit[i + 1] == false) {
				visit[i + 1] = true;
				q[r++] = (ND){i + 1, cur.cnt + 1};
			}

			if (i == 0) {
				break;
			}
		}
	}

	return 0;
}