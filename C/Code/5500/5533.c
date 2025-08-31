#include <stdio.h>

#define MAX_SCORE 100
#define MAX_USER 200
#define MAX_ROUND 3

int input[MAX_ROUND][MAX_USER];
int count[MAX_SCORE + 1];
int score[MAX_USER];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < MAX_ROUND; ++j) {
			scanf("%d", &input[j][i]);
		}
	}
	return;
}

void init() {
	for (int i = 1; i <= MAX_SCORE; ++i) {
		count[i] = 0;
	}
	return;
}

int main() {
	read_input();
	for (int i = 0; i < MAX_ROUND; ++i) {
		init();

		// 현재 라운드에 점수 개수 세기
		for (int j = 0; j < n; ++j) {
			int temp = input[i][j];
			++count[temp];
		}

		// 현재 라운드 점수 반영
		for (int j = 0; j < n; ++j) {
			int temp = input[i][j];
			if (count[temp] == 1) {
				score[j] += temp;
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < n; ++i) {
		printf("%d\n", score[i]);
	}
	return 0;
}