#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int n;
		scanf("%d", &n); // input
		n = n / 2 + 1;	 // if n = 11, n is 6th odd number, So change to 6
		printf("%d\n", n * n);
	}
	return 0;
}