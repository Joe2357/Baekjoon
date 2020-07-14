#include <stdio.h>

int main() {
	int result;
	scanf("%d", &result);
	for (int i = 0; i < 9; i++) {
		int temp;
		scanf("%d", &temp);
		result -= temp;
	}
	printf("%d", result);
	return 0;
}