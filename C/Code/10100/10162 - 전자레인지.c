#include <stdio.h>

int main(t) {
	scanf("%d", &t);
	if (t % 10) // can't set to time
		printf("-1");
	else { // greedy
		printf("%d ", t / 300);
		t %= 300;
		printf("%d ", t / 60);
		t %= 60;
		printf("%d", t / 10);
	}
	return 0;
}