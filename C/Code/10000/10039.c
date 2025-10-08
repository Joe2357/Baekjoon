#include <stdio.h>

const int MAX_STUDENTS = 5;
const int MIN_SCORE = 40;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int sum_score = 0;
	for (int i = 0; i < MAX_STUDENTS; ++i) {
		int x;
		scanf("%d", &x);
		sum_score += max(x, MIN_SCORE);
	}
	printf("%d", sum_score / MAX_STUDENTS);
	return 0;
}