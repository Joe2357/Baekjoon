#include <stdio.h>
#define MAX_INDEX 1000000
#define True 1
#define False 0

typedef char boolean;

boolean isNotPrime[MAX_INDEX + 1] = {True, True};

int main() {

	// prime init
	for (int i = 2; i <= MAX_INDEX; i++)
		if (!isNotPrime[i])
			for (int j = i * 2; j <= MAX_INDEX; j += i)
				isNotPrime[j] = True;

	// loop testcase
	int n;
	for (scanf("%d", &n); n; scanf("%d", &n))
		for (int i = 3; i <= MAX_INDEX; i++)
			if (!isNotPrime[i] && !isNotPrime[n - i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}

	return 0;
}