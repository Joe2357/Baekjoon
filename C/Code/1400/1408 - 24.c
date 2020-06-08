#include <stdio.h>

int main() {
	int hour[2], min[2], sec[2];
	scanf("%d:%d:%d", &hour[0], &min[0], &sec[0]);				// get input
	scanf("%d:%d:%d", &hour[1], &min[1], &sec[1]);
	hour[1] -= hour[0], min[1] -= min[0], sec[1] -= sec[0];		// calculate remaining time
	if (sec[1] < 0)												// second can't be -
		min[1]--, sec[1] += 60;
	if (min[1] < 0)												// minute can't be -
		hour[1]--, min[1] += 60;
	if (hour[1] < 0)											// hour can't be -
		hour[1] += 24;
	if (hour[1] < 10)
		printf("0");											// target < 10
	printf("%d:", hour[1]);
	if (min[1] < 10)
		printf("0");
	printf("%d:", min[1]);
	if (sec[1] < 10)
		printf("0");
	printf("%d", sec[1]);
	return 0;
}