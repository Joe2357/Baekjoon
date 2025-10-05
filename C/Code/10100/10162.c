#include <stdio.h>

const int BUTTON_A = 300;
const int BUTTON_B = 60;
const int BUTTON_C = 10;

int main() {
	int t;
	scanf("%d", &t);
	if (t % BUTTON_C != 0) {
		printf("-1");
	} else {
		printf("%d ", t / BUTTON_A);
		t %= BUTTON_A;
		printf("%d ", t / BUTTON_B);
		t %= BUTTON_B;
		printf("%d", t / BUTTON_C);
	}
	return 0;
}