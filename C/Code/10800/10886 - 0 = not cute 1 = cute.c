#include <stdio.h>

int main() {
	int n, arr[2] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}
	if (arr[0] > arr[1])
		printf("Junhee is not cute!");
	else
		printf("Junhee is cute!");
	return 0;
}