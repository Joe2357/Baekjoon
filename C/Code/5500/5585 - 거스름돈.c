#include <stdio.h>

int main() {
	int arr[6] = { 500, 100, 50, 10, 5, 1 }, input, result = 0, i = 0;
	scanf("%d", &input);
	// change
	input = 1000 - input;
	// greedy
	while (input) {
		if (input >= arr[i])
			result++, input -= arr[i];
		else
			i++;
	}
	printf("%d", result);
	return 0;
}