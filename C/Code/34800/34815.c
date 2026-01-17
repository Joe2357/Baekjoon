#include <stdio.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	k += (k % 2);
	printf("%s", n >= k ? "YES" : "NO");
	return 0;
}