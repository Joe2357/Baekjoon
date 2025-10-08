#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 10000
const int DIGIT = 10;

bool isNotSelfNumber[MAX_IDX + 1 + 1];

int getSelfNumber(int x) {
	int sum = x;
	while (x > 0) {
		sum += x % DIGIT;
		x /= DIGIT;
	}
	return sum;
}

int main() {
	for (int i = 1; i <= MAX_IDX; ++i) {
		isNotSelfNumber[getSelfNumber(i)] = true;
		if (isNotSelfNumber[i] == false) {
			printf("%d\n", i);
		}
	}
	return 0;
}