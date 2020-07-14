#include <stdio.h>

int main() {
	char str[21];
	scanf("%s", str);
	int sum = 0;
	for (int i = 0; str[i]; i++)
		sum += str[i] - 38 - 58 * (str[i] >= 'a');	// 'a' = 97, 'A' = 65
	for (int i = 2; i < sum; i++)					// is prime number?
		if (!(sum % i)) {
			printf("It is not a prime word.");		// is prime number
			return 0;
		}
	printf("It is a prime word.");					// not prime number
	return 0;
}