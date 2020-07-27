#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	int temp = 0;
	while (n > 1)
		temp += n % 2, n /= 2;
	printf("%d", !temp);
	return 0;
}