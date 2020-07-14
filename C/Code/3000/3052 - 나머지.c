#include <stdio.h>

int main(a, t) {
	int arr[42] = { 0 }, result = 0;
	for (t = 10; t; t--) { // for 10 times
		scanf("%d", &a);
		a %= 42, result += (!arr[a]), arr[a] = 1; // add 1 if that remainder didn't used
	}
	printf("%d", result);
	return 0;
}