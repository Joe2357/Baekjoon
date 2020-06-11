#include <stdio.h>

int main(n) {
	int result = 1;
	for (scanf("%d", &n); n; n--) {
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		if (temp1 == result)			// target ball will be at temp2
			result = temp2;
		else if (temp2 == result)		// target ball will be at temp1
			result = temp1;
	}
	printf("%d", result);
	return 0;
}