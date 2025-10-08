#include <stdio.h>

#define MAX_SUBJECT_LEN 50

char subject[MAX_SUBJECT_LEN + 1];
char input_grade[4];
double input_score;

double sum_score;
double sum_grade;

int main() {
	while (scanf("%s %lf %s", subject, &input_score, input_grade) != EOF) {
		switch (input_grade[0]) {
			case 'P': {
				break;
			}
			case 'A': {
				sum_score += input_score;
				if (input_grade[1] == '+') {
					sum_grade += (4.5 * input_score);
				} else {
					sum_grade += (4.0 * input_score);
				}
				break;
			}
			case 'B': {
				sum_score += input_score;
				if (input_grade[1] == '+') {
					sum_grade += (3.5 * input_score);
				} else {
					sum_grade += (3.0 * input_score);
				}
				break;
			}
			case 'C': {
				sum_score += input_score;
				if (input_grade[1] == '+') {
					sum_grade += (2.5 * input_score);
				} else {
					sum_grade += (2.0 * input_score);
				}
				break;
			}
			case 'D': {
				sum_score += input_score;
				if (input_grade[1] == '+') {
					sum_grade += (1.5 * input_score);
				} else {
					sum_grade += (1.0 * input_score);
				}
				break;
			}
			case 'F': {
				sum_score += input_score;
				break;
			}
		}
	}
	printf("%lf", sum_grade / sum_score);
	return 0;
}