#include <stdio.h>

#define MAX_IDX 1000
int input[MAX_IDX][MAX_IDX];
int ans[MAX_IDX][MAX_IDX];
int n;

const int UNABLE = 9999999;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int solve() {
	int ret = 0;

	for (int i = 2; i < n; ++i) {
		int matrix[3][3] = {0};

		// 정답 피라미드와 교환 행렬 생성
		for (int j = 1; j < i; ++j) {
			ans[i][j] = 3 - (ans[i - 1][j - 1] + ans[i - 1][j]);
			++matrix[input[i][j]][ans[i][j]];
		}
		ans[i][0] = 3 - (ans[i - 1][0] + ans[i][1]), ans[i][i] = 3 - (ans[i - 1][i - 1] + ans[i][i - 1]);
		++matrix[input[i][0]][ans[i][0]], ++matrix[input[i][i]][ans[i][i]];

		// 가능한 피라미드인지 체크
		if (matrix[0][1] + matrix[0][2] != matrix[1][0] + matrix[2][0]) {
			return UNABLE;
		}
		if (matrix[1][0] + matrix[1][2] != matrix[0][1] + matrix[2][1]) {
			return UNABLE;
		}
		if (matrix[2][0] + matrix[2][1] != matrix[0][2] + matrix[1][2]) {
			return UNABLE;
		}

		// 지금 0인 것들은 일단 전부 바꿀 예정
		ret += (matrix[1][0] + matrix[2][0] + max(matrix[1][2], matrix[2][1]));
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			scanf("%d", &input[i][j]);
		}
	}

	if (input[0][0] == input[1][0] || input[1][0] == input[1][1] || input[1][1] == input[0][0]) {
		printf("-1");
		return 0;
	}

	ans[0][0] = input[0][0], ans[1][0] = input[1][0], ans[1][1] = input[1][1];
	int r1 = solve();

	ans[0][0] = input[0][0], ans[1][0] = input[1][1], ans[1][1] = input[1][0];
	int r2 = solve();

	if (r1 == UNABLE && r2 == UNABLE) {
		printf("-1");
	} else {
		printf("%d", min(r1, r2 + 1));
	}

	return 0;
}