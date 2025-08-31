#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 13
const int DIGIT = 10;

char isbn[MAX_LEN + 1];

int main() {
	scanf("%s", isbn);

	int temp = 0;
	bool isEvenPosition = false;

	for (int i = 0; i < MAX_LEN; i += 2) { // 홀수 위치
		if (isbn[i] == '*') {
			isEvenPosition = false;
		} else {
			temp += (isbn[i] - '0');
		}
	}
	for (int i = 1; i < MAX_LEN; i += 2) { // 짝수 위치
		if (isbn[i] == '*') {
			isEvenPosition = true;
		} else {
			temp += (3 * (isbn[i] - '0'));
		}
	}

	temp %= DIGIT;
	temp = DIGIT - temp;

	if (isEvenPosition == false) {
		if (temp == DIGIT) {
			temp = 0;
		}
		printf("%d", temp);
	} else {
		for (int i = 0; i < DIGIT; ++i) {
			if ((i * 3 % DIGIT) == (temp % DIGIT)) {
				printf("%d", i);
				break;
			}
		}
	}

	return 0;
}