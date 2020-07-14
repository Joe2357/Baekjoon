#include <stdio.h>

int main() {
	int max = -1, cood[2] = { 0 };
	for (int i = 0; i < 81; i++) {							// 9 * 9 = 81
		int temp;
		scanf("%d", &temp);
		if (temp > max)										// if max value
			max = temp, cood[0] = i / 9, cood[1] = i % 9;	// change value, position
	}
	printf("%d\n", max);
	printf("%d %d", ++cood[0], ++cood[1]);
	return 0;
}