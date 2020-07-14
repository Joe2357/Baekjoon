#include <stdio.h>

int main() {
	int arr[1000001] = { 0 }; // count the number of 0
	for (int i = 0; i < 1000001; i++) { // first init
		int temp = i;
		while (temp) { // search all digits
			if (!(temp % 10))
				arr[i]++;
			temp /= 10;
		}
	}
	arr[0] = 1;
	int t;
	for (scanf("%d", &t); t; t--) {
		int a, b, result = 0;
		scanf("%d %d", &a, &b);
		for (int i = a; i <= b; i++)
			result += arr[i];
		printf("%d\n", result);
	}
	return 0;
}