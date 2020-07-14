#include <stdio.h>

int main() {
	// loop while input is not -1
	while (1) {
		int arr[100] = { 0 }, temp, result = 0;
		// array
		while (1) {
			scanf("%d", &temp);
			// end program
			if (temp == -1)
				return 0;
			// end array input
			else if (!temp)
				break;
			// arr[i] = how many times did i input
			else
				arr[temp] = 1;
		}
		// calc result
		for (int i = 1; i < 50; i++)
			// if i and 2*i exist
			if (arr[i] && arr[2 * i])
				result++;
		printf("%d\n", result);
	}
}