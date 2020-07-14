#include <stdio.h>

int main() {
	int max = 0, maxnum;
	for (int i = 0; i < 9; i++) {
		int temp;
		scanf("%d", &temp);				// input
		if (arr[i] > max)				// if max value
			max = temp, maxnum = i;		// change result
	}
	printf("%d\n%d", max, maxnum + 1);
	return 0;
}