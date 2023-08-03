#include <stdio.h>

#define MAX_IDX 1000
int n;
double arr[MAX_IDX];
double sum;

void printRound(double x) {
	int result = (int)(x * 1000);
	int lastDigit = (int)(x * 10000) % 10;

	if (lastDigit >= 5) {
		++result;
	}
	printf("%.3lf%%\n", (double)result / 1000.0);
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		sum = 0;
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

		printRound(more_than_avg / n * 100);
	}
	return 0;
}