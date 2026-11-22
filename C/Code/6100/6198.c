#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 80000

int stack[MAX_IDX], top = -1;
int n;

int main() {
	scanf("%d", &n);
	long long ans = 0LL;

	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		while (top >= 0 && stack[top] <= x) {
			top -= 1;
		}
		ans += (top + 1);
		stack[++top] = x;
	}

	printf("%lld", ans);
	return 0;
}