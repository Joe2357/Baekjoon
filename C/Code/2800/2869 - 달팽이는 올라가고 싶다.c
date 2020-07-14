#include <stdio.h>

int main() {
	long long a, b, v;
	scanf("%lld %lld %lld", &a, &b, &v);
	long long day = (v - a) / (a - b), temp = (v - a) % (a - b);
	if (temp)   // remained
		day++;
	printf("%lld", ++day);  // next day snail can climb all
	return 0;
}