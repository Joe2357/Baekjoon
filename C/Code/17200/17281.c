#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_INNING 50
#define MAX_PLAYER 9
#define MAX_BASE 4
const int ONE_BASE = 1;
const int TWO_BASE = 2;
const int THREE_BASE = 3;
const int HOMERUN = 4;
const int OUT = 0;

int performance[MAX_INNING + 1][MAX_PLAYER + 1];
int n;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= MAX_PLAYER; ++j) {
			scanf("%d", &performance[i][j]);
		}
	}
	return;
}

int getSimulationResult(int* arr) {
	int score = 0;
	int current_player = 0;

	for (int inning = 1; inning <= n; ++inning) {
		int bases = 0; // 시간초과에 대응하기 위한 비트마스킹 변경

		for (int out_count = 0; out_count < 3; current_player = (current_player + 1) % MAX_PLAYER) {
			if (performance[inning][arr[current_player]] == OUT) {
				out_count += 1;
			} else { // 타자 및 모든 주자가 진루해야함
				int move_cnt = performance[inning][arr[current_player]];
				bases = (bases << move_cnt) | (1 << (move_cnt - 1));
                for (int temp = 8; temp <= 64; temp <<= 1) { // 3, 4, 5, 6번 비트 탐색
                    score += ((bases & temp) > 0);
                }
                bases &= 7; // 0, 1, 2 bit만 남기기
			}
		}
	}

	return score;
}

int solve(int* arr, bool* v, int l) {
	if (l == MAX_PLAYER) { // 순열이 완성되어있음
		return getSimulationResult(arr);
	}

	if (l == 3) { // 4번 타자는 항상 1번이어야 함
		arr[l] = 1;
		return solve(arr, v, l + 1);
	}

	int ret = 0;
	for (int i = 2; i <= MAX_PLAYER; ++i) {
		if (v[i] == false) {
			v[i] = true;
			arr[l] = i;
            int current_result = solve(arr, v, l + 1);
			ret = max(ret, current_result); // max 안에 함수 절대 쓰지 않기
			v[i] = false;
		}
	}

	return ret;
}

int main() {
	read_input();

	// 우선 순열을 만들어야한다. 이 때 1번 player는 항상 4번이어야 한다.
	int player_list[MAX_PLAYER] = {0};
	bool visit[MAX_PLAYER + 1 + 1] = {false};
	printf("%d", solve(player_list, visit, 0));
	return 0;
}