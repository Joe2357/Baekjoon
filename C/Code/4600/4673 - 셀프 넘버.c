#include <stdio.h>

int arr[10100];

void d(int n) {
	int temp = n;
	while (n)
		temp += n % 10, n /= 10;
	arr[temp] = 1;
	return;
}

int main() {
	for (int i = 1; i < 10000; i++) {
		// find i's constructor
		d(i);

		// if self number
		if (!arr[i])
			printf("%d\n", i);
	}
	return 0;
}