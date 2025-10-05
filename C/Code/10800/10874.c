#include <stdio.h>

const int MAX_PROBLEM = 10;
const int MOD = 5;

int main() {
	int n;
	scanf("%d", &n);
	for (int student = 1; student <= n; ++student) {
		int solved = 0;

		for (int problem = 1; problem <= MAX_PROBLEM; problem++) {
			int ans;
			scanf("%d", &ans);
			solved += (ans == (problem - 1) % MOD + 1);
		}
		if (solved == MAX_PROBLEM) {
			printf("%d\n", student);
		}
	}
	return 0;
}