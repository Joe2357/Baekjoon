#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;
typedef struct Node {
	int x, y;
} ND;

#define STD 5
bool isDDu[STD] = {true, false, false, true, false};
int r, c;

ll dp[STD * 2 + 1][STD * 2 + 1];

#define DIR 4
ND dir[DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

typedef struct QueueNode {
	ND pos;
	int cnt;
	ND vis[STD];
} QN;
#define MAX_IDX ((STD * 2) * (STD * 2) * STD + 1)

ll getSubResult(int maxR, int maxC, ND start) {
	QN q[MAX_IDX];
	int f = 0, r = 0;

	q[r++] = (QN){start, 1, {start}};
	ll ret = 0;

	while (f < r) {
		QN cur = q[f++];
		if (cur.cnt == STD) {
			++ret;
			continue;
		}

		for (int i = 0; i < DIR; ++i) {
			ND next = (ND){cur.pos.x + dir[i].x, cur.pos.y + dir[i].y};
			bool isVisited = false;
			for (int j = 0; j < cur.cnt; ++j) {
				if (next.x == cur.vis[j].x && next.y == cur.vis[j].y) {
					isVisited = true;
					break;
				}
			}

			if (isVisited == false && next.x >= 0 && next.x < maxR && next.y >= 0 && next.y < maxC) {
				if (isDDu[(next.x * c + next.y) % STD] == isDDu[cur.cnt]) {
					q[r].pos = next, q[r].cnt = cur.cnt + 1;
					for (int j = 0; j < cur.cnt; ++j) {
						q[r].vis[j] = cur.vis[j];
					}
					q[r++].vis[cur.cnt] = next;
				}
			}
		}
	}

	return ret;
}

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
void init() {
	for (int i = 1; i <= min(r, STD * 2); ++i) {
		for (int j = 1; j <= min(c, STD * 2); ++j) {
			ll ret = 0;
			for (int a = 0; a < i; ++a) {
				for (int b = 0; b < j; ++b) {
					if (isDDu[(a * c + b) % STD] == true) {
						ret += getSubResult(i, j, (ND){a, b});
					}
				}
			}
			dp[i][j] = ret;
		}
	}
	return;
}

void print_result() {
	ll ret = 0;
	int squR = max(0, (r - STD) / STD), squC = max(0, (c - STD) / STD);
	r -= (squR * STD), c -= (squC * STD);

	ret += ((squR * squC) * (dp[STD * 2][STD * 2] - dp[STD * 2][STD] - dp[STD][STD * 2] + dp[STD][STD]));
	ret += ((squR) * (dp[STD * 2][c] - dp[STD][c]));
	ret += ((squC) * (dp[r][STD * 2] - dp[r][STD]));
	ret += dp[r][c];

	printf("%lld", ret);
	return;
}

int main() {
	scanf("%d %d", &r, &c);
	init();
	print_result();
	return 0;
}