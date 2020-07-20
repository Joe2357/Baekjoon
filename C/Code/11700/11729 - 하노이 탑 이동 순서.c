#include <stdio.h>
#include <math.h>

void hanoi(int round, int start, int end) {
	// move the highest pane
	if (round == 1)
		printf("%d %d\n", start, end);
	else if (round == 2) { // move 2 highest pane
		printf("%d %d\n", start, 6 - start - end);
		printf("%d %d\n", start, end);
		printf("%d %d\n", 6 - start - end, end);
	}
	else { // n pane move = (n - 2) pane move + move the lowest pane
		hanoi(round - 2, start, end);
		printf("%d %d\n", start, 6 - start - end);
		hanoi(round - 2, end, 6 - start - end);
		printf("%d %d\n", start, end);
		hanoi(round - 2, 6 - start - end, start);
		printf("%d %d\n", 6 - start - end, end);
		hanoi(round - 2, start, end);
	}
	return;
}

int main(n) {
	scanf("%d", &n);
	printf("%.0lf\n", pow(2, n) - 1); // count of movement
	hanoi(n, 1, 3);					  // start recursion
	return 0;
}