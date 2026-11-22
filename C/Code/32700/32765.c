#include <stdio.h>

typedef long long lld;

#define MAX_IDX 40000 // experiment

lld mult[MAX_IDX];
int last;

void init(lld first_salary) {
	mult[1] = first_salary + 1;
	last = 1;

	for (int i = 2; i < mult[i - 1]; ++i) {
		mult[i] = (mult[i - 1] * (i - 1) / i * i + i) / i;
		last = i;
	}

	return;
}

lld solve(int x) {
	if (x <= last) {
		return mult[x] * x;
	} else {
		return (mult[last] * last) + (mult[last] * (x - last));
	}
}

int main() {
	lld x;
	int q;
	scanf("%lld %d", &x, &q);

	init(x);

	while (q--) {
		int a;
		scanf("%d", &a);
		printf("%lld\n", solve(a));
	}
	return 0;
}