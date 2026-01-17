#include <stdio.h>

#define MAX_IDX (int)(1e6)
const int MOD = 26;

char str[MAX_IDX + 1];
int a, b;

void read_input() {
	scanf("%d %d %s", &a, &b, str);
	return;
}

void solve() {
	for (int i = 0; str[i] != '\0'; ++i) {
		str[i] = (a * (str[i] - 'A') + b) % MOD + 'A';
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		read_input();
		solve();
		printf("%s\n", str);
	}
	return 0;
}