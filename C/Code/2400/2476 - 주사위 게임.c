#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int main(t) {
	int result = 0;
	for (scanf("%d", &t); t; t--) {
		int arr[7] = { 0 }, temp, boolean = 0;		// arr = dice count
		for (int i = 0; i < 3; i++) {
			scanf("%d", &temp);
			arr[temp]++;
			boolean += (arr[temp] > 1);				// there is a value more than 2
		}
		if (boolean)
			for (int i = 1; i < 7; i++) {			// price calc
				temp = 0;
				if (arr[i] == 3)					// every value is same
					temp = 10000 + 1000 * i;		// calc 1
				else if (arr[i] == 2)
					temp = 1000 + 100 * i;			// calc 2
				result = max(result, temp);			// finding max value
			}
		else										// every value is not same
			for (int i = 6; i > 0; i--)
				if (arr[i]) {						// find biggest value
					temp = i * 100;					// calc 3
					result = max(result, temp);
					break;
				}
	}
	printf("%d", result);
	return 0;
}