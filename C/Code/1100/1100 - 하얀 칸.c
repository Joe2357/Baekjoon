#include <stdio.h>

int main() {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		char str[10];
		scanf("%s", str);									// setting grid
		for (int j = 0; j < 8; j++)
			if (( str[j] == 'F' ) && !( ( i + j ) % 2 ))	// white point & pawn exist
				result++;
	}
	printf("%d", result);
	return 0;
}