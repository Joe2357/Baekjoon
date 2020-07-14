#include <stdio.h>

int main(n) {
	int point = 0, conti = 0;
	for (scanf("%d", &n); n; n--) {
		int temp;
		scanf("%d", &temp);
		if (temp)					// if correct
			point += ++conti;
		else						// if not correct
			conti = 0;
	}
	printf("%d", point);
	return 0;
}