#include <stdio.h>

typedef long long ll;

const int LENGTH_OF_ALPHABET = 26;

int get_offset(ll a, int b) {
	int ret = 1;
	a %= LENGTH_OF_ALPHABET;

	while (b > 0) {
		if (b % 2 == 1) {
			ret = (ret * a) % LENGTH_OF_ALPHABET;
		}
		a = (a * a) % LENGTH_OF_ALPHABET;
		b /= 2;
	}
	return ret;
}

int main() {
	int n, b;
	ll a;
	char c;

	scanf("%d %lld %d\n", &n, &a, &b);
	int offset = get_offset(a, b);

	for (int i = 0; i < n; ++i) {
		scanf("%c", &c);

		if (c == ' ') {
			printf(" ");
		} else {
			char new_c = c - offset;
			if (new_c < 'A') {
				new_c += LENGTH_OF_ALPHABET;
			}
			printf("%c", new_c);
		}
	}

	return 0;
}