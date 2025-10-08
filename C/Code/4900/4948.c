#include <stdio.h>
#define MAX_INDEX 246913

int main(t) {
	// 1 is not a prime
	int arr[MAX_INDEX] = {1};

	// first init
	for (int i = 2; i < MAX_INDEX; i++)
		// if prime number
		if (!arr[i])
			// multiple of i is not a prime
			for (int a = i * 2; a < MAX_INDEX; a += i)
				arr[a] = 1;

	// test case
	while (scanf("%d", &t) && t) {
		int result = 0;
		// from t+1 to 2*t
		for (int i = t + 1; i <= 2 * t; i++)
			// plus 1 if prime number
			result += (!arr[i]);
		printf("%d\n", result);
	}
	return 0;
}