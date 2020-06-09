#include <stdio.h>

int main() {
	int arr[10] = { 0 }, temp;
	scanf("%d", &temp);
	while (temp)						// get all digit
		arr[temp % 10]++, temp /= 10;	// arr[n] = how many times did n appear?
	for (int i = 9; i >= 0; i--)
		for (; arr[i]; arr[i]--)
			printf("%d", i);
	return 0;
}