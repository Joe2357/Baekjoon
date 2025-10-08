#include <stdio.h>

int main(n, temp, max, min) {
	int arr[100000] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (!i)
			arr[i] = temp, max = temp, min = temp;
		else {
			arr[i] = arr[i - 1] + temp; // arr[a] = sum of arr[0] ~ arr[a - 1] + new value
			if (max < arr[i] - min)		// if min < 0, max value will arr[i] - min
				max = arr[i] - min;
			if (max < arr[i]) // else max value will arr[i]
				max = arr[i];
			if (min > arr[i]) // finding minimum value : sum of arr[o] ~ arr[i]
				min = arr[i];
		}
	}
	printf("%d", max);
	return 0;
}