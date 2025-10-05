#include <stdio.h>

int fibo(int x) {
	if (x < 2) {
		return x;
	} else {
		return fibo(x - 1) + fibo(x - 2);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));
	return 0;
}