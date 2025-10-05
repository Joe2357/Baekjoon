#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void solve(int a, int b, int c) {
	int sum = a + b + c, max_s = max(a, max(b, c));
	if (max_s >= sum - max_s) {
		printf("Invalid\n");
	} else if (a == b && b == c) {
		printf("Equilateral\n");
	} else if (a == b || b == c || c == a) {
		printf("Isosceles\n");
	} else {
		printf("Scalene\n");
	}
	return;
}

int main() {
	while (true) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) {
			break;
		} else {
			solve(a, b, c);
		}
	}
	return 0;
}