#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int temp;

		for (scanf("%d", &temp); temp; temp--)
			printf("=");
		printf("\n");
	}
	return 0;
}