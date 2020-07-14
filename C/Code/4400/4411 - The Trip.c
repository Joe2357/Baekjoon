#include <stdio.h>
// Warn : floating point!
int main(n) {
	for (scanf("%d", &n); n; scanf("%d", &n)) {
		int arr[1000], sum = 0;
		for (int i = 0; i < n; i++) { // integer calc ( more More accurate )
			int dollars, cents;
			scanf("%d.%d", &dollars, &cents);
			arr[i] = dollars * 100 + cents;
			sum += arr[i];
		}
		double avg = (double)sum / n, taken = 0, given = 0;
		for (; n; n--) { // more? less?
			double temp = arr[n - 1] - avg;
			if (temp < 0)
				taken += -(int)temp / 100.0;
			else
				given += (int)temp / 100.0;
		}
		printf("$%.2f\n", taken > given ? taken : given);
	}
	return 0;
}