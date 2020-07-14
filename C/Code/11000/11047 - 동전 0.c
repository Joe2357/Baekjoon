#include <stdio.h>

int main() {
	int arr[10], n, k, sum = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	n--;
	while (n + 1) { // greedy
		sum += k / arr[n];
		k %= arr[n--];
	}
	printf("%d", sum);
}