#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	int n;
	scanf("%d", &n);
	int big[3] = { 0 }, small[3] = { 0 };

	while (n--) {
		int input[3], a, b, c;
		scanf("%d %d %d", input, input + 1, input + 2);
		a = max(big[0], big[1]) + input[0];
		b = max(big[0], max(big[1], big[2])) + input[1];
		c = max(big[1], big[2]) + input[2];
		big[0] = a, big[1] = b, big[2] = c;

		a = min(small[0], small[1]) + input[0];
		b = min(small[0], min(small[1], small[2])) + input[1];
		c = min(small[1], small[2]) + input[2];
		small[0] = a, small[1] = b, small[2] = c;
	}

	printf("%d %d", max(big[0], max(big[1], big[2])), min(small[0], min(small[1], small[2])));
	return 0;
}