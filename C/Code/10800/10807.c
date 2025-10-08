#include <stdio.h>

#define MAX_VAL 100

int cnt[2 * MAX_VAL + 1];

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		cnt[x + MAX_VAL] += 1;
	}
	int v;
	scanf("%d", &v);
	printf("%d\n", cnt[v + MAX_VAL]);
	return 0;
}