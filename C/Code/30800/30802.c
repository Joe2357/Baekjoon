#include <stdio.h>

#define MAX_SIZE 6

int main() {
	int n;
	int size[MAX_SIZE];
	int t, p;
	scanf("%d", &n);
	for (int i = 0; i < MAX_SIZE; ++i) {
		scanf("%d", size + i);
	}
	scanf("%d %d", &t, &p);

	int ret = 0;
	for (int i = 0; i < MAX_SIZE; ++i) {
		ret += ((size[i] / t) + (size[i] % t > 0));
	}
	printf("%d\n%d %d", ret, n / p, n % p);

	return 0;
}