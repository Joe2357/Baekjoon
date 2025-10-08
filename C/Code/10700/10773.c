#include <stdio.h>

int main() {
	int arr[100000], top = -1, k;
	long long sum = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &temp);
		if (!temp)
			sum -= arr[top--];
		else {
			arr[++top] = temp;
			sum += temp;
		}
	}
	printf("%lld", sum);
	return 0;
}