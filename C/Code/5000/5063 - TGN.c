#include <stdio.h>

int main(n, r, e, c) {
	for (scanf("%d", &n); n; n--) {
		scanf("%d %d %d", &r, &e, &c);
		if (r > e - c)
			printf("do not advertise\n");
		else if (r < e - c)
			printf("advertise\n");
		else
			printf("does not matter\n");
	}
	return 0;
}