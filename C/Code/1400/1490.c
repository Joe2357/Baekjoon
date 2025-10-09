#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;
#define DIGIT 10
const int MAX_INTERVAL = 5 * 7 * 8 * 9;

bool isDigitinNumber[DIGIT + 1];
ll n;

void init(ll x) {
	ll temp = x;
	while (temp > 0) {
		isDigitinNumber[temp % 10] = true;
		temp /= DIGIT;
	}
	return;
}

bool check(ll x) {
	bool ret = true;
	for (int i = 1; i < DIGIT; ++i) {
		if (isDigitinNumber[i] == true) {
			ret &= (x % i == 0);
		}
	}
	return ret;
}

int main() {
	scanf("%lld", &n);
	init(n);

	if (check(n) == true) {
		printf("%lld", n);
		return 0;
	}

	ll standard_number = n * 10;
	for (int i = 0; i < DIGIT; ++i) {
		ll current_number = standard_number + i;
		if (check(current_number) == true) {
			printf("%lld", current_number);
			return 0;
		}
	}

	standard_number *= 10;
	for (int i = 0; i < DIGIT * DIGIT; ++i) {
		ll current_number = standard_number + i;
		if (check(current_number) == true) {
			printf("%lld", current_number);
			return 0;
		}
	}

	standard_number *= 10;
	for (int i = 0; i < DIGIT * DIGIT * DIGIT; ++i) {
		ll current_number = standard_number + i;
		if (check(current_number) == true) {
			printf("%lld", current_number);
			return 0;
		}
	}

	standard_number *= 10;
	for (int i = 0; i < DIGIT * DIGIT * DIGIT * DIGIT; ++i) {
		ll current_number = standard_number + i;
		if (check(current_number) == true) {
			printf("%lld", current_number);
			return 0;
		}
	}

	return 0;
}