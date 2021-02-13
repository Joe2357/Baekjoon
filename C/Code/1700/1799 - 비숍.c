#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(x) ((x) < 0 ? (-(x)) : (x))

typedef char boolean;
#define True 1
#define False 0

typedef struct Position {
	int x, y;
} PS;

#define M_S 10
boolean grid[M_S][M_S + 1]; int len;
int answer[2];
#define M_L 50
PS empty[2][M_L]; int s_l[2];
#define WHITE 0
#define BLACK 1

int used[M_L]; int l;

boolean isAvailable(int m, int n) {
	boolean canBePlace = True;
	for (int i = 0; i < l && canBePlace; ++i) {
		canBePlace &= (abs(empty[m][used[i]].x - empty[m][n].x) != abs(empty[m][used[i]].y - empty[m][n].y));
	}

	return canBePlace;
}

void backtrack(int count, int mode, int num) {
	if (num == s_l[mode]) {
		answer[mode] = max(answer[mode], count);
		return;
	}

	if (isAvailable(mode, num)) {
		used[l++] = num;
		++count;
		backtrack(count, mode, num + 1);
		--count, --l;
	}

	backtrack(count, mode, num + 1);
	return;
}

int main() {
	scanf("%d", &len);
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			int a;
			scanf("%d", &a);
			if (a) {
				grid[i][j] = True;
				int t = (i + j) & 1;
				empty[t][s_l[t]++] = (PS) { i, j };
			}
		}
	}

	backtrack(0, WHITE, 0);
	backtrack(0, BLACK, 0);

	printf("%d", answer[0] + answer[1]);
	return 0;
}