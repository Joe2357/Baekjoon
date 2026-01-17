#include <stdio.h>

#define MAX_IDX 300
const int SCISSORS = 1, ROCK = 2, PAPER = 3;
const int A_WIN = 1, B_WIN = 2, DRAW = 0;

int tempA[MAX_IDX], tempB[MAX_IDX];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tempA[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &tempB[i]);
	}
	return;
}

int get_game_result(int a, int b) {
	if (a == b) {
		return DRAW;
	} else if ((a == SCISSORS && b == PAPER) ||
			   (a == ROCK && b == SCISSORS) ||
			   (a == PAPER && b == ROCK)) {
		return A_WIN;
	} else {
		return B_WIN;
	}
}

int main() {
	read_input();

	int ret = 1, current_win_team = get_game_result(tempA[0], tempB[0]), current_win_streak = 1;
	for (int i = 1; i < n; ++i) {
		int game_result = get_game_result(tempA[i], tempB[i]);

		if (game_result == DRAW) {
			ret = max(ret, current_win_streak);
			current_win_streak = 1;
			current_win_team = 3 - current_win_team; // switch team
		} else {
			if (game_result == current_win_team) {
				current_win_streak += 1;
			} else {
				ret = max(ret, current_win_streak);
				current_win_streak = 1;
				current_win_team = game_result;
			}
		}
	}

	printf("%d", max(ret, current_win_streak));
	return 0;
}