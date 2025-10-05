#include <stdio.h>

#define MAX_LEN 1000

int n;
int b;

int main() {
	scanf("%d %d", &n, &b);

	char ret[MAX_LEN];
	int l = 0;
	for (l = 0; n > 0; n /= b) {
		int remainder = n % b;

		if (remainder < 10) {
			ret[l++] = remainder + '0';
		} else {
			ret[l++] = remainder - 10 + 'A';
		}
	}
	ret[l--] = '\0';

	// reverse
	for (int i = 0; i < l; i += 1, l -= 1) {
		char c = ret[i];
		ret[i] = ret[l];
		ret[l] = c;
	}
	printf("%s", ret);
	return 0;
}