#include <stdio.h>

int main(n) {
	int arr[1001] = { 1,1 };						// prime grid
	for (int i = 2; i <= 1000; i++)					// prime = 0, not prime = 1
		if (!arr[i])
			for (int a = i * 2; a <= 1000; a += i)
				arr[a] = 1;
	int result = 0;
	for (scanf("%d", &n); n; n--) {					// checking
		int temp;
		scanf("%d", &temp);
		result += (!arr[temp]);						// if prime? +1
	}
	printf("%d", result);
	return 0;
}