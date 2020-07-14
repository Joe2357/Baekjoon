#include <stdio.h>
#define min(a, b) (a > b) ? b : a

int cmp(int *a, int *b) { // integer ascending order
	return *a - *b;
}

int GCD(int a, int b) { // Euclidean algorithm
	if (!b)
		return a;
	return GCD(b, a % b);
}

int main(n) {
	int arr[100], tarr[10000], a = 0, temp = 1000000001;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), cmp); // ascending order
	for (int i = 0; i < n - 1; i++)
		temp = min(temp, arr[i + 1] - arr[i]); // find minimum distract of values
	temp = GCD(arr[n - 1] - arr[0], temp);     // GCD of minimum distract & (biggest - smallest)
	for (int i = 2; i * i <= temp; i++) { // finding common divisor
		if (!(temp % i)) {
			tarr[a++] = i;
			if (i * i != temp)
				tarr[a++] = temp / i;
		}
	}
	tarr[a++] = temp;                 // not 1 but GCD is common divisor
	qsort(tarr, a, sizeof(int), cmp); // sort common divisor
	for (int i = 0; i < a; i++)
		printf("%d ", tarr[i]);
	return 0;
}