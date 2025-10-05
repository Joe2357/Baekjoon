#include <stdio.h>

int main(t, temp) {
	int ret = 1;
	int n;
	scanf("%d", &n);
	while (n--) {
		int a;
		scanf("%d", &a);
		ret += (a - 1);
	}
	printf("%d", ret);
	return 0;
}