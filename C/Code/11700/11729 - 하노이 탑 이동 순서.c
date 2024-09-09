#include <stdio.h>

const int FIRST = 1, MIDDLE = 2, LAST = 3, ALL = 6;
int n;

void print_hanoi(int x, int s, int e) {
	if (x == 1) {
		printf("%d %d\n", s, e);
	} else {
		print_hanoi(x - 1, s, ALL - s - e);
		printf("%d %d\n", s, e);
		print_hanoi(x - 1, ALL - s - e, e);
	}
	return;
}

int main() {
	scanf("%d", &n);
	printf("%d\n", (1 << n) - 1);
	print_hanoi(n, FIRST, LAST);
	return 0;
}