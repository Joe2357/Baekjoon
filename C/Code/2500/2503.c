#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Question {
	int value;
	int strike;
	int ball;
} Question;

#define MAX_QUESTIONS 100

Question questions[MAX_QUESTIONS];
int n;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &questions[i].value, &questions[i].strike, &questions[i].ball);
	}
	return;
}

bool isAllDifferentDigits(int x) {
	int hundreds = x / 100;
	int tens = (x / 10) % 10;
	int ones = x % 10;
	bool digitCheck = (hundreds != tens) && (hundreds != ones) && (tens != ones);
	bool isZeroNotIncluded = (hundreds != 0) && (tens != 0) && (ones != 0);
	return digitCheck && isZeroNotIncluded;
}

bool isFeasibleAnswer(int x) {
	for (int i = 0; i < n; ++i) {
		int strike = 0;
		int ball = 0;

		int q_hundreds = questions[i].value / 100;
		int q_tens = (questions[i].value / 10) % 10;
		int q_ones = questions[i].value % 10;

		int x_hundreds = x / 100;
		int x_tens = (x / 10) % 10;
		int x_ones = x % 10;

		strike += (q_hundreds == x_hundreds);
		strike += (q_tens == x_tens);
		strike += (q_ones == x_ones);

		ball += ((q_hundreds == x_tens) || (q_hundreds == x_ones));
		ball += ((q_tens == x_hundreds) || (q_tens == x_ones));
		ball += ((q_ones == x_hundreds) || (q_ones == x_tens));

		if (strike != questions[i].strike || ball != questions[i].ball) {
			return false;
		}
	}
	return true;
}

int main() {
	read_input();
	int ret = 0;
	for (int x = 100; x < 1000; ++x) {
		if (isAllDifferentDigits(x) == true) {
			ret += isFeasibleAnswer(x);
		}
	}
	printf("%d", ret);
	return 0;
}