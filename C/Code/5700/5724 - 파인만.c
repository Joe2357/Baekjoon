#include <stdio.h>

int main() {
	int arr[101] = { 0, 1 }, a;
	for (int i = 2; i < 101; i++)
		arr[i] = arr[i - 1] + i * i; // dp with rules
	for (scanf("%d", &a); a; scanf("%d", &a))
		printf("%d\n", arr[a]);
	return 0;
}