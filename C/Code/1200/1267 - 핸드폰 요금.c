#include <stdio.h>

int main(t) {
	int rY = 0, rM = 0;
	for (scanf("%d", &t); t; t--) {
		int n;
		scanf("%d", &n);
		rY += ((n / 30 + 1) * 10), rM += ((n / 60 + 1) * 15);		// calc
	}
	if (rY > rM)				// M is cheaper than Y
		printf("M %d", rM);
	else if (rY < rM)			// Y is cheaper than M
		printf("Y %d", rY);
	else						// they are same
		printf("Y M %d", rY);
	return 0;
}