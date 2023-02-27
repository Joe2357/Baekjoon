#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	int x, y;
} ND;

#define INF 987654321
#define MAX_IDX 50
#define MAX_CHICKEN 13

#define EMPTY 0
#define HOME 1
#define CHICKEN 2

#define abs(x) (((x) < 0) ? (-(x)) : (x))
#define min(a, b) (((a) > (b)) ? (b) : (a))

ND home[MAX_IDX * 2];
ND chicken[MAX_CHICKEN];
int homeLen, chickenLen;
int n, m;
int retval;

int getDistance(ND a, ND b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

bool select[MAX_CHICKEN];
void backtrack(int x, int selected) {
	if (selected == m) {
		int tempRetval = 0;

		for (int i = 0; i < homeLen; ++i) {
			int temp = INF;

			for (int j = 0; j < chickenLen; ++j) {
				if (select[j] == true) {
					temp = min(temp, getDistance(home[i], chicken[j]));
				}
			}
			tempRetval += temp;
		}

		retval = min(retval, tempRetval);
		return;
	}
	if (x == chickenLen) {
		return;
	}

	select[x] = true;
	backtrack(x + 1, selected + 1);
	select[x] = false;
	backtrack(x + 1, selected);

	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int t;
			scanf("%d", &t);
			switch (t) {
				case HOME: {
					home[homeLen++] = (ND){i, j};
					break;
				}
				case CHICKEN: {
					chicken[chickenLen++] = (ND){i, j};
					break;
				}
			}
		}
	}

	retval = INF;

	backtrack(0, 0);

	printf("%d", retval);
	return 0;
}