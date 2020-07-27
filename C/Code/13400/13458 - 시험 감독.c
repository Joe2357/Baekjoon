#include <stdio.h>

int main(n) {
	long long arr[1000000], result = 0, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", arr + i);

	scanf("%lld %lld", &b, &c);

	for (int i = 0; i < n; i++)
		result += (arr[i] <= b) ? 1 : 1 + ((arr[i] - b) / c) + ((arr[i] - b) % c > 0);

	printf("%lld", result);
	return 0;
}