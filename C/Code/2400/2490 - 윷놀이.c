#include <stdio.h>

int main() {
	char str[6] = "DCBAE";				// string index
	for (int i = 0; i < 3; i++) {
		int result = 0;
		for (int j = 0; j < 4; j++) {
			int temp;
			scanf("%d", &temp);
			result += temp;				// counting 1
		}
		printf("%c\n", str[result]);	// indexing
	}
	return 0;
}