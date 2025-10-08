#include <stdio.h>

const int MAX_PLACE = 4;

int main() {
	int time = 0;
	for (int i = 0; i < MAX_PLACE; ++i) {
		int x;
		scanf("%d", &x);
		time += x;
	}
	printf("%d\n%d", time / 60, time % 60);
	return 0;
}