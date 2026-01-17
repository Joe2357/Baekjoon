#include <stdio.h>

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	int patty, cheeze;
	scanf("%d %d", &patty, &cheeze);
	printf("%d", min(patty, cheeze + 1) + min(patty - 1, cheeze));
	return 0;
}