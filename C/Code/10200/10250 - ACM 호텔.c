#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		int temp1 = n % h, temp2 = n / h + 1;
		if (!temp1) // temp2 will be n/h
			temp1 = h, temp2--;
		printf("%d\n", 100 * temp1 + temp2);
	}
	return 0;
}