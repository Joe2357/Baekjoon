#include <stdio.h>

typedef char boolean;
#define True 1
#define False 0

#define MAX_INDEX 500

int n = 1, m;
int parent[MAX_INDEX + 1];
boolean isTree[MAX_INDEX + 2];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

int main() {
	for (int t = 0; n != 0 || m != 0; scanf("%d %d", &n, &m), ++t) {
		if (t == 0) {
			continue;
		}

		int result = n;
		for (int i = 1; i <= n; ++i) {
			parent[i] = i;
			isTree[i] = True;
		}
		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			int x = find(a), y = find(b);

			if (x != y) {
				if (isTree[x] || isTree[y]) {
					--result;
				}
				if (!isTree[x] || !isTree[y]) {
					isTree[x] = isTree[y] = False;
				}

				if (x > y) {
					parent[a] = parent[x] = y;
				}
				else {
					parent[b] = parent[y] = x;
				}
			}
			else {
				if (isTree[x]) {
					isTree[x] = False;
					--result;
				}
			}
		}

		printf("Case %d: ", t);
		switch (result) {
			case 0:
			{
				printf("No trees.\n");
				break;
			}
			case 1:
			{
				printf("There is one tree.\n");
				break;
			}
			default:
			{
				printf("A forest of %d trees.\n", result);
				break;
			}
		}
	}

	return 0;
}