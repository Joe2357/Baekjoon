#include <stdio.h>

int main() {
	int n, f;
	scanf("%d %d", &n, &f);
	n = n / 100 * 100; // 뒤 2자리를 00으로 변경

	int remainder = n % f;
	int result = (remainder == 0) ? 0 : f - remainder;
	printf("%02d", result);
	return 0;
}