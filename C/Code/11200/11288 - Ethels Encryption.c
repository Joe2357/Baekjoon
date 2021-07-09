#include <stdio.h>

const int ALP = 26;

char str[10001];

int power(int x, int y) {
	if (y == 0) {
		return 1;
	} else if (y == 1) {
		return x;
	}

	int t = power(x, y >> 1);
	t %= ALP;
	int r = (t * t) % ALP;
	if (y & 1) {
		r *= x, r %= ALP;
	}

	return r;
}

int main() {
	int n, a, b;
	long long t;
	scanf("%d %lld %d", &n, &t, &b);

	a = t % ALP;
	int offset = power(a, b);

	gets(str);	// clear buffer
	gets(str);
	for (int i = 0; str[i]; ++i) {
		if (str[i] != ' ') {
			str[i] -= offset;
			if (str[i] < 'A') {
				str[i] += ALP;
			}
		}
	}

	printf("%s", str);
	return 0;
}