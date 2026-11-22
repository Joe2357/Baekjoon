#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int ret = 1;
	while (n--) {
		ret *= 2;
	}
	printf("%d", ret);
	return 0;
}