#include <stdio.h>

int main(t) {
	int isNotPrime[10001] = { 1, 1 };
	for (int i = 2; i <= 10000; i++)
		if (!isNotPrime[i])
			for (int a = i * 2; a <= 10000; a += i)
				isNotPrime[a] = 1;
	for (scanf("%d", &t); t; t--) {
		int n;
		scanf("%d", &n);
		int a = n / 2, temp = 0;
		while (isNotPrime[a + temp] || isNotPrime[a - temp])
			temp++;
		printf("%d %d\n", a - temp, a + temp);
	}
	return 0;
}