#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) < (b)) ? (b) : (a))

#define M_I (int)1e6
int parent[M_I + 1];
int n, m;

void init() {
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}
	return;
}

int find(int x) {
	if (parent[x] != x) {
		return parent[x] = find(parent[x]); /* change root node every query */
	}
	else {
		return x;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	init();

	char result[2][4] = { "NO", "YES" };

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			int d = find(b), e = find(c);
			if (d != e) {
				parent[find(b)] = find(c);
			}
		}
		else if (a == 1) {
			printf("%s\n", result[find(b) == find(c)]);
		}
	}

	return 0;
}