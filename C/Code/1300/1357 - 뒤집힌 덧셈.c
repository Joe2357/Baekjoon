#include <stdio.h>

int rev(int a) {							// make reverse int function
	int temp = 0;
	while (a)
		temp = temp * 10 + a % 10, a /= 10;
	return temp;
}

int main(x, y) {
	scanf("%d %d", &x, &y);
	printf("%d", rev(rev(x) + rev(y)));
	return 0;
}