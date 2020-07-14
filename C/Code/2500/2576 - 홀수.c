#include <stdio.h>

int main() {
	int result = 0, min = 100;			// max input = 100
	for (int i = 0; i < 7; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp % 2) {					// if odd number
			result += temp;
			if (temp < min)				// if minimum odd number
				min = temp;
		}
	}
	if (!result)						// if no odd number
		printf("-1");
	else {
		printf("%d\n", result);
		printf("%d", min);
	}
	return 0;
}