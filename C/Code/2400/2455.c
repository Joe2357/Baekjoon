#include <stdio.h>

const int MAX_STATION = 4;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	int person = 0, result = 0;
	for (int i = 0; i < MAX_STATION; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		person += (b - a);
		result = max(result, person);
	}
	printf("%d", result);
	return 0;
}