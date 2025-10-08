#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

bool isInSameMatch(int a, int b) {
	return (a + 1) / 2 == (b + 1) / 2;
}
int getNextNumber(int x) {
	return (x + 1) / 2;
}

int main() {
	int n;
	scanf("%d", &n);
	int jimin, hansu;
	scanf("%d %d", &jimin, &hansu);

	int round;
	for (round = 1; isInSameMatch(jimin, hansu) == false; ++round) {
		jimin = getNextNumber(jimin);
		hansu = getNextNumber(hansu);
	}
	printf("%d", round);
	return 0;
}