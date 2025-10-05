#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 10000

bool isNotPrime[MAX_IDX + 1 + 1];

#define min(a, b) (((a) > (b)) ? (b) : (a))

void prime_init() {
	isNotPrime[0] = true;
	isNotPrime[1] = true;
	for (int i = 2; i <= MAX_IDX; ++i) {
		if (isNotPrime[i] == false) {
			for (int j = i * 2; j <= MAX_IDX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}

int main() {
	prime_init();

	int m, n;
	scanf("%d %d", &m, &n);

	int sum_of_prime = 0, min_of_prime = MAX_IDX + 1;
	for (int i = m; i <= n; i++) {
		if (isNotPrime[i] == false) {
			sum_of_prime += i;
			min_of_prime = min(min_of_prime, i);
		}
	}
	if (sum_of_prime == 0) {
		printf("-1");
	} else {
		printf("%d\n%d", sum_of_prime, min_of_prime);
	}
	return 0;
}