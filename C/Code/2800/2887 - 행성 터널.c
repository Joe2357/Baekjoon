#include <stdio.h>

typedef struct Path {
	long long w;
	int s, e;
} Path;
typedef struct Node {
	long long x, y, z;
	int idx;
} ND;
typedef char boolean;
#define True 1
#define False 0

#define MAX_INDEX (int)1e5

ND node[MAX_INDEX];
Path x[MAX_INDEX];
Path y[MAX_INDEX];
Path z[MAX_INDEX];
int parent[MAX_INDEX + 1];
int n;
int merged = 1;
long long result;

int cmpX(ND* a, ND* b) {
	return a->x > b->x;
}
int cmpY(ND* a, ND* b) {
	return a->y > b->y;
}
int cmpZ(ND* a, ND* b) {
	return a->z > b->z;
}
int cmp(Path* a, Path* b) {
	return a->w > b->w;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

boolean merge(int a, int b) {
	int x = find(a), y = find(b);

	if (x == y) {
		return False;
	}
	else {
		if (x > y) {
			parent[a] = parent[x] = y;
		}
		else {
			parent[b] = parent[y] = x;
		}

		++merged;
		return True;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		node[i] = (ND) { a, b, c, i };
	}
	qsort(node, n, sizeof(ND), cmpX);
	for (int i = 0; i < n - 1; ++i) {
		x[i] = (Path) { node[i + 1].x - node[i].x, node[i].idx, node[i + 1].idx };
	}
	qsort(x, n - 1, sizeof(Path), cmp);
	qsort(node, n, sizeof(ND), cmpY);
	for (int i = 0; i < n - 1; ++i) {
		y[i] = (Path) { node[i + 1].y - node[i].y, node[i].idx, node[i + 1].idx };
	}
	qsort(y, n - 1, sizeof(Path), cmp);
	qsort(node, n, sizeof(ND), cmpZ);
	for (int i = 0; i < n - 1; ++i) {
		z[i] = (Path) { node[i + 1].z - node[i].z, node[i].idx, node[i + 1].idx };
	}
	qsort(z, n - 1, sizeof(Path), cmp);

	int a = 0, b = 0, c = 0;
	while (merged < n) {
		long long
			A = x[a].w,
			B = y[b].w,
			C = z[c].w;

		if (A <= B && A <= C) {
			if (merge(x[a].s, x[a].e)) {
				result += A;
			}
			++a;
		}
		else if (B <= A && B <= C) {
			if (merge(y[b].s, y[b].e)) {
				result += B;
			}
			++b;
		}
		else {
			if (merge(z[c].s, z[c].e)) {
				result += C;
			}
			++c;
		}
	}

	printf("%lld", result);
	return 0;
}