#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 531441 // 3^12
const char STICK = '-';
const char EMPTY = ' ';
const int BASE = 3;

char ans[MAX_LEN + 1];

void recursion(int s, int e, int x) {
	if (x == 1) {
		return;
	} else {
		x /= 3;

		recursion(s, s + x, x);
		for (int i = x; i < x * 2; ++i) {
			ans[s + i] = EMPTY;
		}
		recursion(s + x * 2, e, x);
	}
	return;
}

void solve(int n) {
	int l = 1;
	for (int i = 0; i < n; ++i) {
		l *= BASE;
	}
	for (int i = 0; i < l; ++i) {
		ans[i] = STICK;
	}
	ans[l] = '\0';

	recursion(0, l, l);

	printf("%s\n", ans);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		solve(n);
	}
	return 0;
}