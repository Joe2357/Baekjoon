#include <stdio.h>

int main(t) {
	int arr[10001] = { 0 }; // number range is not much large
	for (scanf("%d", &t); t; t--) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++; // count number 
	}
	for (int i = 0; i < 10001; i++)
		for (int k = 0; k < arr[i]; k++)
			printf("%d\n", i);
	return 0;
}