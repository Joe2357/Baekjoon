/**
 * BOJ 2025 :: Knight Tour
 * Memory :: 8048KB
 * Time :: 964ms
 * Result (testcase) :: 228 / 256
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_IDX 666
#define MOVE_COUNT 8
const int NONE = -1;

typedef struct {
	int x, y;
} Position;

const Position moves[MOVE_COUNT] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int n;
int backup_degree[MAX_IDX][MAX_IDX];
int degree[MAX_IDX][MAX_IDX];
Position path[MAX_IDX * MAX_IDX];
Position start;

// 격자 범위 확인
bool is_in(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

// 실행하지 않아도 불가능한 경우 체크 (색깔 기준 판단)
bool is_impossible_parity() {
	if (n % 2 == 0) {
		return false;
	}
	return ((start.x + start.y) % 2 != 0);
}

// 초기 degree 계산
void init_degree_map() {
	// 1. 전체 8로 초기화 (중앙)
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			backup_degree[i][j] = 8;
		}
	}

	// 2. 테두리 안쪽 (6)
	for (int i = 1; i < n - 1; ++i) {
		backup_degree[1][i] = 6;
		backup_degree[n - 2][i] = 6;
		backup_degree[i][1] = 6;
		backup_degree[i][n - 2] = 6;
	}

	// 3. 외각 변 (4)
	for (int i = 1; i < n - 1; ++i) {
		backup_degree[0][i] = 4;
		backup_degree[n - 1][i] = 4;
		backup_degree[i][0] = 4;
		backup_degree[i][n - 1] = 4;
	}

	// 4. 꼭짓점 인접 (3)
	backup_degree[0][1] = 3;
	backup_degree[1][0] = 3;
	backup_degree[0][n - 2] = 3;
	backup_degree[1][n - 1] = 3;
	backup_degree[n - 2][0] = 3;
	backup_degree[n - 1][1] = 3;
	backup_degree[n - 2][n - 1] = 3;
	backup_degree[n - 1][n - 2] = 3;

	// 5. 꼭짓점 (2)
	backup_degree[0][0] = 2;
	backup_degree[n - 1][0] = 2;
	backup_degree[0][n - 1] = 2;
	backup_degree[n - 1][n - 1] = 2;

	return;
}

// 2단계: 주변 degree 합 계산
int get_secondary_degree(int x, int y) {
	int sum = 0;
	for (int i = 0; i < MOVE_COUNT; ++i) {
		int nx = x + moves[i].x;
		int ny = y + moves[i].y;
		if (is_in(nx, ny) == true && degree[nx][ny] > NONE) {
			sum += degree[nx][ny];
		}
	}
	return sum;
}

// 3단계: 중앙으로부터의 거리 (클수록 좋음 -> 벽타기 유도)
int get_dist_from_center(int x, int y) {
	// 유클리드 거리 제곱 사용
	// 중심좌표 * 2를 해서 정수 연산으로 처리
	int cx = (n - 1);
	int cy = (n - 1);
	int dx = (x * 2) - cx;
	int dy = (y * 2) - cy;
	return dx * dx + dy * dy;
}

bool solve() {
	memcpy(degree, backup_degree, sizeof(backup_degree));

	Position cur = start;
	int total_steps = n * n;
	int path_len = 0;

	for (int step = 0; step < total_steps; ++step) {
		path[path_len++] = cur;
		degree[cur.x][cur.y] = NONE; // 방문 처리

		// 주변 degree 갱신
		for (int i = 0; i < MOVE_COUNT; i++) {
			int nx = cur.x + moves[i].x;
			int ny = cur.y + moves[i].y;
			if (is_in(nx, ny) == true && degree[nx][ny] > NONE) {
				degree[nx][ny] -= 1;
				if (degree[nx][ny] == 0 && step < total_steps - 2) { // 고립된 칸 발생
					return false;
				}
			}
		}

		if (step == total_steps - 1) {
			return true;
		}

		// 다음 이동 후보 선정 (Warnsdorff's Rule)
		int min_deg = 9;
		int candidates[8];
		int c_cnt = 0;

		// 1. Min Degree 찾기
		for (int i = 0; i < MOVE_COUNT; i++) {
			int nx = cur.x + moves[i].x;
			int ny = cur.y + moves[i].y;
			if (is_in(nx, ny) == true && degree[nx][ny] > NONE) {
				int d = degree[nx][ny];
				if (d < min_deg) {
					min_deg = d;
					c_cnt = 0;
					candidates[c_cnt++] = i;
				} else if (d == min_deg) {
					candidates[c_cnt++] = i;
				}
			}
		}

		if (c_cnt == 0) {
			return false; // 갈 곳 없음
		}

		int best_move_idx = -1;

		if (c_cnt == 1) {
			best_move_idx = candidates[0];
		} else {
			// Tie-Breaking 시작
			int min_sec_deg = 999;
			// 2차 후보군 (Secondary degree까지 같은 애들)
			int final_candidates[8];
			int f_cnt = 0;

			for (int i = 0; i < c_cnt; i++) {
				int idx = candidates[i];
				int nx = cur.x + moves[idx].x;
				int ny = cur.y + moves[idx].y;

				int sec_deg = get_secondary_degree(nx, ny);

				if (sec_deg < min_sec_deg) {
					min_sec_deg = sec_deg;
					f_cnt = 0;
					final_candidates[f_cnt++] = idx;
				} else if (sec_deg == min_sec_deg) {
					final_candidates[f_cnt++] = idx;
				}
			}

			if (f_cnt == 1) {
				best_move_idx = final_candidates[0];
			} else {
				// 3차 후보군 (중앙으로부터 먼 위치부터 탐색)
				int max_dist = -1;
				int dist_candidates[8];
				int d_cnt = 0;

				for (int i = 0; i < f_cnt; i++) {
					int idx = final_candidates[i];
					int nx = cur.x + moves[idx].x;
					int ny = cur.y + moves[idx].y;

					int dist = get_dist_from_center(nx, ny);

					if (dist > max_dist) {
						max_dist = dist;
						d_cnt = 0;
						dist_candidates[d_cnt++] = idx;
					} else if (dist == max_dist) {
						dist_candidates[d_cnt++] = idx;
					}
				}
				// 그래도 같으면 랜덤
				best_move_idx = dist_candidates[rand() % d_cnt];
			}
		}

		cur.x += moves[best_move_idx].x;
		cur.y += moves[best_move_idx].y;
	}

	return true;
}

int main() {
	srand(time(NULL));
	scanf("%d %d %d", &n, &start.x, &start.y);
	start.x -= 1, start.y -= 1;

	if (is_impossible_parity() == true) {
		printf("-1 -1");
		return 0;
	}

	// 초기화는 메인에서 딱 한 번만 수행
	init_degree_map();

	for (int trial = 0; trial < 100; ++trial) {
		if (solve() == true) {
			for (int i = 0; i < n * n; ++i) {
				printf("%d %d\n", path[i].x + 1, path[i].y + 1);
			}
			return 0;
		}
	}

	printf("-1 -1");
	return 0;
}