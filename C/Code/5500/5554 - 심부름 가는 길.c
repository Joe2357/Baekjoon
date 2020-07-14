#include <stdio.h>

int main() {
	int sec = 0;
	for (int i = 0; i < 4; i++) {
		int a;
		scanf("%d", &a);
		sec += a;
	}
	printf("%d\n%d", sec / 60, sec % 60);
	return 0;
}