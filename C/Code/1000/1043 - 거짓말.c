#include <stdio.h>

typedef char bool;
const bool False = 0;
const bool True = 1;

#define MAX_IDX (50 + 1)

int partyMember[MAX_IDX][MAX_IDX];
int parent[MAX_IDX];
int n, m;
int result;

int find(int x) {
	if (x == parent[x]) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
void merge(int x, int y) {
	int A = find(x), B = find(y);

	if (A > B) {
		parent[x] = parent[A] = B;
	} else if (A < B) {
		parent[y] = parent[B] = A;
	}
	return;
}

int main() {
	for (int i = 1; i < MAX_IDX; ++i) {
		parent[i] = i;
	}
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= m; ++i) {
		int a;
		scanf("%d", &a);
		for (int j = 0; j < a; ++j) {
			int x;
			scanf("%d", &x);
			partyMember[i][j] = x;
			merge(x, partyMember[i][0]);
		}
	}

	int truthGroup = find(partyMember[0][0]);
	for (int i = 1; i <= m; ++i) {
		bool canLie = True;
		for (int j = 0; partyMember[i][j] > 0; ++j) {
			canLie &= (find(partyMember[i][j]) != truthGroup);
		}

		result += canLie;
	}

	printf("%d", result);
	return 0;
}