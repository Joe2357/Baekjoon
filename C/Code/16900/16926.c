#include <stdio.h>

#define MAX_IDX 300

int grid[MAX_IDX][MAX_IDX];
int n, m, r;
int buffer[MAX_IDX * 4];
int buffer_size;

#define min(a, b) ((a) < (b) ? (a) : (b))

void read_input() {
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}
	return;
}

void solve() {
	int total_layers = min(n, m) / 2;

	/* 외각의 ring부터 하나씩 재배열 */
	for (int layer = 0; layer < total_layers; ++layer) {
		int start_row = layer;
		int start_col = layer;
		int end_row = n - layer - 1;
		int end_col = m - layer - 1;

		buffer_size = 0; // 버퍼 초기화

		/* ring의 값을 버퍼에 저장 */
		for (int i = start_col; i <= end_col; ++i) { // 상단 행
			buffer[buffer_size++] = grid[start_row][i];
		}
		for (int i = start_row + 1; i <= end_row; ++i) { // 오른쪽 열
			buffer[buffer_size++] = grid[i][end_col];
		}
		for (int i = end_col - 1; i >= start_col; --i) { // 하단 행
			buffer[buffer_size++] = grid[end_row][i];
		}
		for (int i = end_row - 1; i > start_row; --i) { // 왼쪽 열
			buffer[buffer_size++] = grid[i][start_col];
		}

		int rotation = r % buffer_size; // 실제로 회전할 칸 수
		int cur_idx = rotation;			// 버퍼에서 값을 읽어올 인덱스

		/* 다시 ring에 값을 채워넣기 */
		for (int i = start_col; i <= end_col; ++i) { // 상단 행
			grid[start_row][i] = buffer[cur_idx];
			cur_idx = (cur_idx + 1) % buffer_size;
		}
		for (int i = start_row + 1; i <= end_row; ++i) { // 오른쪽 열
			grid[i][end_col] = buffer[cur_idx];
			cur_idx = (cur_idx + 1) % buffer_size;
		}
		for (int i = end_col - 1; i >= start_col; --i) { // 하단 행
			grid[end_row][i] = buffer[cur_idx];
			cur_idx = (cur_idx + 1) % buffer_size;
		}
		for (int i = end_row - 1; i > start_row; --i) { // 왼쪽 열
			grid[i][start_col] = buffer[cur_idx];
			cur_idx = (cur_idx + 1) % buffer_size;
		}
	}
	return;
}

void print_result() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	return;
}

int main() {
	read_input();
	solve();
	print_result();
	return 0;
}