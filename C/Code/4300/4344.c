#include <stdio.h>

#define MAX_IDX 1000
int n;
double arr[MAX_IDX];

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		double sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lf", arr + i);
			sum += arr[i];
		}

		double avg = sum / n;
		double more_than_avg = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i] > avg) {
				more_than_avg += 1;
			}
		}

		printf("%.3lf%%\n", more_than_avg / n * 100);
	}
	return 0;
}