#include <stdio.h>
#include <math.h>

typedef struct Position {
	double x, y;
} PS;
typedef struct Path {
	double w;
	int s, e;
} Path;
typedef char boolean;
#define True 1
#define False 0;

#define MAX_IDX 1000

int n, m;
PS pos[MAX_IDX];
Path path[MAX_IDX * MAX_IDX]; int len;
int parent[MAX_IDX + 1];
int merged = 1;
double result;

int cmp(Path* a, Path* b) {
	return a->w > b->w;
}

double getDistance(PS* a, PS* b) {
	return sqrt((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
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
			parent[x] = parent[a] = y;
		}
		else {
			parent[y] = parent[b] = x;
		}
		++merged;
		return True;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		pos[i] = (PS) { a, b };

		parent[i] = i;

		for (int j = 0; j < i; ++j) {
			path[len++] = (Path) { getDistance(pos + j, pos + i), j, i };
		}
	}
	qsort(path, len, sizeof(Path), cmp);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(--a, --b);
	}

	int i = 0;
	while (merged < n) {
		Path p = path[i++];

		if (merge(p.s, p.e)) {
			result += p.w;
		}
	}

	printf("%.2lf", result);
	return 0;
}