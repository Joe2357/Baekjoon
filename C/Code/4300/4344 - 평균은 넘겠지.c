#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int arr[1000], n = 0;
		scanf("%d", &n);
		float avg = 0.0, people = 0;
		for (int k = 0; k < n; k++) {
			scanf("%d", &arr[k]);
			avg += arr[k];
		}
		avg /= n; // average calc
		for (int i = 0; i < n; i++)
			if (arr[i] > avg)
				people++;          // people who does not exceed average
		people /= n, people * 100; // percentage calc
		printf("%.3f%%\n", people);
	}
	return 0;
}