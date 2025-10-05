#include <stdio.h>

typedef long long ll;

#define DIGIT 10

int count[DIGIT];

int main() {
	ll a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	ll mul = a * b * c;

	while (mul > 0) {
		count[mul % DIGIT] += 1;
		mul /= DIGIT;
	}

	for (int i = 0; i < DIGIT; i++) {
		printf("%d\n", count[i]);
	}
	return 0;
}