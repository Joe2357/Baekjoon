#include <stdio.h>
#include <math.h>

typedef struct Path {
	double w;
	int s, e;
} Path;
typedef struct Position {
	double x, y;
} PS;

#define MAX_IDX 100

PS pos[MAX_IDX];
int parent[MAX_IDX]; int merged = 1;
int n;
Path path[MAX_IDX * MAX_IDX]; int len;
double result;

double getDistance(PS* a, PS* b) {
	return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

int cmp(Path* a, Path* b) {
	return a->w < b->w;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}

typedef char boolean;
#define True 1
#define False 0
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
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		double a, b;
		scanf("%lf %lf", &a, &b);
		pos[i] = (PS) { a, b };
		for (int j = 0; j < i; ++j) {
			path[len++] = (Path) { getDistance(&pos[j], &pos[i]), j, i };
		}
	}
	qsort(path, len, sizeof(Path), cmp);

	while (merged < n) {
		Path a = path[--len];
		if (merge(a.s, a.e)) {
			result += a.w;
		}
	}

	printf("%.3lf", result);
	return 0;
}