#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int sum_sticks = a + b + c;
	int max_stick = max(a, max(b, c));

	if (max_stick >= sum_sticks - max_stick) {
		sum_sticks -= (max_stick - (sum_sticks - max_stick) + 1);
	}
	printf("%d", sum_sticks);
	return 0;
}