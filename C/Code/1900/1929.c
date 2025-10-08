#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

bool isNotPrime[1000001] = {true, true};

int main(m, n) {
	for (int i = 2; i <= 1000000; i++)
		if (!isNotPrime[i])
			for (int a = i * 2; a <= 1000000; a += i)
				isNotPrime[a] = true;
	for (scanf("%d %d", &m, &n); m <= n; m++)
		if (!isNotPrime[m])
			printf("%d\n", m);
	return 0;
}