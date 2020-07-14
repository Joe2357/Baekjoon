#include <stdio.h>
#define max(a, b) (arr[a] > arr[b]) ? a : b

int main() {
	int arr[101] = { 0 }, avg = 0, a = 0;
	for (int i = 0; i < 10; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp / 10]++;                   // every number is multiple of 10
		avg += temp;                        // average sum
	}
	for (int i = 100; i; i--)               // mode (Most Counted)
		a = max(a, i);
	printf("%d\n%d", avg / 10, a * 10);     // print result
	return 0;
}