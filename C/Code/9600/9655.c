#include <stdio.h>

#define MAX_IDX 1000
const int CY = 0, SK = 1;

int winner[MAX_IDX + 1];
int n;

void init() {
	winner[1] = SK;
	winner[2] = CY;
	winner[3] = SK;
	for (int i = 4; i <= MAX_IDX; ++i) {
		if (winner[i - 1] == CY || winner[i - 3] == CY) {
			winner[i] = SK;
		} else {
			winner[i] = CY;
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	init();
	printf("%s", winner[n] == SK ? "SK" : "CY");
	return 0;
}