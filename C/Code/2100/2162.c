#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LINE 3000

typedef struct Line {
	int x1, y1, x2, y2;
} Line;

Line line[MAX_LINE + 1];
int parent[MAX_LINE + 1];
int n;

int group[MAX_LINE + 1];
int group_cnt, max_cnt;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

void read_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		line[i] = (Line){x1, y1, x2, y2};
	}
	return;
}

void init() {
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}
	return;
}

int find(int x) {
	if (x == parent[x]) {
		return x;
	} else {
		return parent[x] = find(parent[x]);
	}
}
void merge(int a, int b) {
	int x = find(a), y = find(b);
	parent[b] = parent[y] = x;
	return;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (temp > 0) {
		return 1;
	} else if (temp < 0) {
		return -1;
	} else {
		return 0;
	}
}

bool isIntersect(int i, int j) {
	Line l1 = line[i], l2 = line[j];

	int res1 = ccw(l1.x1, l1.y1, l1.x2, l1.y2, l2.x1, l2.y1) * ccw(l1.x1, l1.y1, l1.x2, l1.y2, l2.x2, l2.y2);
	int res2 = ccw(l2.x1, l2.y1, l2.x2, l2.y2, l1.x1, l1.y1) * ccw(l2.x1, l2.y1, l2.x2, l2.y2, l1.x2, l1.y2);

	if (res1 == 0 && res2 == 0) {
		if (max(l1.x1, l1.x2) < min(l2.x1, l2.x2)) {
			return false;
		} else if (max(l2.x1, l2.x2) < min(l1.x1, l1.x2)) {
			return false;
		} else if (max(l1.y1, l1.y2) < min(l2.y1, l2.y2)) {
			return false;
		} else if (max(l2.y1, l2.y2) < min(l1.y1, l1.y2)) {
			return false;
		} else {
			return true;
		}
	} else {
		return res1 <= 0 && res2 <= 0;
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (find(i) != find(j) && isIntersect(i, j) == true) {
				merge(i, j);
			}
		}
	}
	return;
}

void get_result() {
	for (int i = 1; i <= n; ++i) {
		group[find(i)] += 1;
		max_cnt = max(max_cnt, group[find(i)]);
	}
	for (int i = 1; i <= n; ++i) {
		group_cnt += (group[i] > 0);
	}
	return;
}

int main() {
	read_input();
	init();
	solve();
	get_result();
	printf("%d\n%d", group_cnt, max_cnt);
	return 0;
}