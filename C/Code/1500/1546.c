#include <stdio.h>

#define MAX_IDX 1000

double score[MAX_IDX];
int n;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &score[i]);
	}
	return;
}

int main() {
	read_input();

	// 점수 최댓값 찾기
	double max_score = 0;
	for (int i = 0; i < n; ++i) {
		max_score = max(max_score, score[i]);
	}

	// 점수 고치기
	for (int i = 0; i < n; ++i) {
		score[i] = (score[i] * 100) / max_score;
	}

	// 평균 구하기
	double sum = 0.0;
	for (int i = 0; i < n; ++i) {
		sum += score[i];
	}
	double avg = sum / n;

	printf("%.3lf", avg);
	return 0;
}