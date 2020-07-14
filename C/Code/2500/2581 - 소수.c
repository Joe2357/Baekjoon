#include <stdio.h>

int main(m, n) {
	int arr[10001] = { 1, 1 };
	for (int i = 2; i < 10001; i++)                 // Eratos algorithm
		if (!arr[i])
			for (int a = i * 2; a < 10001; a += i)
				arr[a] = 1;
	int sum = 0, min;
	for (scanf("%d %d", &m, &n); n >= m; n--)
		if (!arr[n])                                // if prime number
			sum += n, min = n;
	if (!sum && !min)
		printf("-1");
	else
		printf("%d\n%d", sum, min);
	return 0;
}