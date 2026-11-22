#include <stdio.h>

typedef struct Position {
	int x, y;
} PS;

#define MAX_IDX 20
#define MAX_DIR 4

int r, c;
char grid[MAX_IDX][MAX_IDX + 1];
PS dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

#define max(a, b) (((a) > (b)) ? (a) : (b))

int solve(PS cur, int cnt, int v) {
	int temp_v = (1 << (grid[cur.x][cur.y] - 'A'));
	if ((v & temp_v) == 0) { /* not visited */
		v |= temp_v;
		int temp_cnt = cnt + 1;

		for (int i = 0; i < MAX_DIR; ++i) {
			PS new_cur = (PS){cur.x + dir[i].x, cur.y + dir[i].y};
			if (0 <= new_cur.x && new_cur.x < r && 0 <= new_cur.y && new_cur.y < c) {
				temp_cnt = max(temp_cnt, solve(new_cur, cnt + 1, v));
			}
		}
		return temp_cnt;

	} else {
		return cnt;
	}
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", grid[i]);
	}

	printf("%d", solve((PS){0, 0}, 0, 0));
	return 0;
}