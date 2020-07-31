#include <stdio.h>

int main(n) {
	int arr[1001] = { 0 };
	for (int a = 1; a <= 998; a++) {
		for (int b = 1; b <= 1000; b++) {
			if (a + b > 1000)
				break;
			for (int c = 1; c <= 1000; c++) {
				if (a + b + c <= 1000) {
					arr[a + b + c]++;
				}
				else
					break;
			}
		}
	}
	scanf("%d", &n);
	printf("%d", arr[n / 3]);
	return 0;
}