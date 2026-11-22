#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_BOARD 2000
const int INF = MAX_BOARD * MAX_BOARD;
const char WHITE = 'W';
const char BLACK = 'B';

#define min(a, b) (((a) > (b)) ? (b) : (a))

char board[MAX_BOARD + 1][MAX_BOARD + 1];
bool diff[MAX_BOARD + 1][MAX_BOARD + 1];
int psW[MAX_BOARD + 2][MAX_BOARD + 2];
int n, m, k;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", board[i]);
	}

	// diff 채우기
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			diff[i][j] = (board[i][j] != (((i + j) % 2 == 0) ? WHITE : BLACK));
		}
	}

	// diff 누적합 계산
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			psW[i][j] = psW[i - 1][j] + psW[i][j - 1] - psW[i - 1][j - 1] + diff[i - 1][j - 1];
		}
	}

	// 8x8 크기에서의 정답 도출
	int ret = INF;
	for (int i = k; i <= n; ++i) {
		for (int j = k; j <= m; ++j) {
			int cur = psW[i][j] - psW[i - k][j] - psW[i][j - k] + psW[i - k][j - k];
			ret = min(ret, min(cur, (k * k) - cur));
		}
	}

    // 결과 출력
	printf("%d", ret);
	return 0;
}
