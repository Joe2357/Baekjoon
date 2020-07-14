#include <stdio.h>

int main(t) {
	int arr[201] = { 0 }; // -100 ~ 100
	for (scanf("%d", &t); t; t--) {
		int temp;
		scanf("%d", &temp);
		arr[temp + 100]++; // index count
	}
	int target;
	scanf("%d", &target);
	printf("%d", arr[target + 100]);
	return 0;
}