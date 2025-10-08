#include <stdio.h>

const int STEP = 4;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i += STEP) {
		printf("long ");
	}
	printf("int");
	return 0;
}