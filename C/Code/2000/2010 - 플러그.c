#include <stdio.h>

int main(t, temp) {
	int result = 1;					// at least 1 plug
	for (scanf("%d", &t); t; t--) {	// tc
		scanf("%d", &temp);
		result += temp - 1;			// using 1 plug, can get temp plugs
	}
	printf("%d", result);
	return 0;
}