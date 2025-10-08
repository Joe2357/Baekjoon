#include <stdio.h>
#include <stdlib.h>

#define TOTAL_QUESTIONS 8
#define SELECTED_QUESTIONS 5

typedef struct Problem {
	int point, num;
} PROBLEM;

PROBLEM problems[TOTAL_QUESTIONS];

int score_desc(const void* a, const void* b) {
	return ((PROBLEM*)b)->point - ((PROBLEM*)a)->point;
}
int number_asc(const void* a, const void* b) {
	return ((PROBLEM*)a)->num - ((PROBLEM*)b)->num;
}

int main() {
	for (int i = 0; i < TOTAL_QUESTIONS; ++i) {
		int x;
		scanf("%d", &x);
		problems[i] = (PROBLEM){x, i + 1};
	}

	qsort(problems, TOTAL_QUESTIONS, sizeof(PROBLEM), score_desc);
	qsort(problems, SELECTED_QUESTIONS, sizeof(PROBLEM), number_asc);

	int total_score = 0;
	for (int i = 0; i < SELECTED_QUESTIONS; ++i) {
		total_score += problems[i].point;
	}

	printf("%d\n", total_score);
	for (int i = 0; i < SELECTED_QUESTIONS; ++i) {
		printf("%d ", problems[i].num);
	}
	return 0;
}