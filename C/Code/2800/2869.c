#include <stdio.h>

int main() {
	long long a, b, v;
	scanf("%lld %lld %lld", &a, &b, &v);
	long long day = (v - a) / (a - b), temp = (v - a) % (a - b);
	if (((v - a) % (a - b)) > 0) {
		day = day + 1; // 아직 한번에 올라갈 수 없다
	}
	printf("%lld", ++day); // 마지막날 계산
	return 0;
}