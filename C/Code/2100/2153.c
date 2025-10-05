#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 20
#define MAX_NUMBER (52 * MAX_LEN)

bool isNotPrime[MAX_NUMBER + 1 + 1];
char str[MAX_LEN + 1];

int convert_to_number(char c) {
	if ('a' <= c && c <= 'z') {
		return c - 'a' + 1;
	} else {
		return c - 'A' + 27;
	}
}

void prime_init() {
	isNotPrime[0] = true;
	isNotPrime[1] = false; // 이 문제에서는 1도 소수다..
	for (int i = 2; i <= MAX_NUMBER; ++i) {
		if (isNotPrime[i] == false) {
			for (int j = i * 2; j <= MAX_NUMBER; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}

int main() {
	scanf("%s", str);

	int sum = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		sum += convert_to_number(str[i]);
	}

	prime_init();
	if (isNotPrime[sum] == true) {
		printf("It is not a prime word.");
	} else {
		printf("It is a prime word.");
	}
	return 0;
}