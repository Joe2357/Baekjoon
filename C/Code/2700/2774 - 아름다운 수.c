#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) // TC
	{
		int arr[10] = { 0 }, result = 0, target;
		for (scanf("%d", &target); target; target /= 10)       // checking all digits
			result += !(arr[target % 10]), arr[target % 10]++; // result + 1 if not appeared, but now appear
		printf("%d\n", result);
	}
	return 0;
}