#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int x, y;
} ND;

#define MAX_WALK (50 * 20)
#define MAX_IDX 100
ND store[MAX_IDX];
int n;
ND start, end;

ND q[MAX_IDX];
bool v[MAX_IDX];
int f, r;

#define abs(x) (((x) < 0) ? (-(x)) : (x))

int dist(ND a, ND b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		// visit init
		for (int i = 0; i < n; ++i) {
			v[i] = false;
		}

		scanf("%d", &n);
		scanf("%d %d", &start.x, &start.y);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &store[i].x, &store[i].y);
		}
		scanf("%d %d", &end.x, &end.y);

		if (dist(start, end) <= MAX_WALK) {
			printf("happy\n");
			continue;
		}

		f = r = 0;
		for (int i = 0; i < n; ++i) {
			if (dist(start, store[i]) <= MAX_WALK) {
				v[i] = true;
				q[r++] = store[i];
			}
		}

		bool canHappy = false;
		while (f < r) {
			ND cur = q[f++];
			if (dist(cur, end) <= MAX_WALK) {
				canHappy = true;
				break;
			}
			for (int i = 0; i < n; ++i) {
				if (v[i] == false && dist(cur, store[i]) <= MAX_WALK) {
					v[i] = true;
					q[r++] = store[i];
				}
			}
		}
		printf("%s\n", (canHappy == true ? "happy" : "sad"));
	}
}