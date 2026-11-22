#include <stdio.h>
#define MOD 1000000007

long long arr[2][2] = { {1,1},{1,0} };
long long n;

void matrixMultiple(long long b[][2]) {
	int c[2][2] = {
		{((arr[0][0] * b[0][0]) % MOD + (arr[0][1] * b[1][0]) % MOD) % MOD, ((arr[1][0] * b[0][0]) % MOD + (arr[1][1] * b[1][0]) % MOD) % MOD},
		{((arr[0][0] * b[0][1]) % MOD + (arr[0][1] * b[1][1]) % MOD) % MOD, ((arr[1][0] * b[0][1]) % MOD + (arr[1][1] * b[1][1]) % MOD) % MOD}
	};

	arr[0][0] = c[0][0],
		arr[0][1] = c[0][1],
		arr[1][0] = c[1][0],
		arr[1][1] = c[1][1];

	return;
}

void matrixPower(long long x) {
	if (x < 2)
		return;

	long long temp[2][2] = {
		{arr[0][0],arr[0][1]},
		{arr[1][0],arr[1][1]}
	};
	matrixMultiple(temp);
	matrixPower(x >> 1);

	if (x & 1) {
		matrixMultiple(temp);
	}

	return;
}

int main() {
	scanf("%lld", &n);

	if (n == 0) {
		printf("0");
	}
	else if (n < 3) {
		printf("1");
	}
	else {
		matrixPower(n - 1);
		printf("%d", arr[0][0]);
	}

	return 0;
}