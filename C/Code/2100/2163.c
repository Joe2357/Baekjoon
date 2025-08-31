#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	// 초콜릿 조각을 1번 쪼개면 조각의 개수가 1개 늘어난다
	// 즉, 초콜릿 nm 조각을 만들기 위해서는, 쪼개는 행위를 nm - 1번 하면 된다
	printf("%d", n * m - 1);
	return 0;
}