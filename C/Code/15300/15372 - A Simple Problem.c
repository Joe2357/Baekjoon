#include <stdio.h>

long long n;

int main(t) {
	for(scanf("%d", &t); t; t--) {
		scanf("%lld", &n);
		printf("%ld\n", n * n);
	}
	
	return 0;
}