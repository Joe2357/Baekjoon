#include <stdio.h>

/* 재귀를 이용한 구현 */
int get_gcd(int a, int b) {
	return ((b > 0) ? (get_gcd(b, a % b)) : (a));
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);

		// 최대공약수 계산
		int gcd = get_gcd(a, b);

		// 최소공배수 x 최대공약수 = a x b
		int lcm = (a * b) / gcd;

		printf("%d\n", lcm);
	}
	return 0;
}