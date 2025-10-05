#include <stdio.h>

const int INIT_SCORE = 100;

int main() {
	int score_a = INIT_SCORE, score_b = INIT_SCORE;
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a > b) {
			score_b -= a;
		} else if (a < b) {
			score_a -= b;
		}
	}
	printf("%d\n%d", score_a, score_b);
	return 0;
}