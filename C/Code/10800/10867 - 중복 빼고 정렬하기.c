#include <stdio.h>

int main(n) {
	int arr[2001] = { 0 }; // -1000 ~ 1000
	for (scanf("%d", &n); n; n--) {
		int temp;
		scanf("%d", &temp);
		arr[temp + 1000]++; // add index
	}
	for (int i = 0; i < 2001; i++)
		if (arr[i])					 // if exists
			printf("%d ", i - 1000); // print only 1 time
	return 0;
}