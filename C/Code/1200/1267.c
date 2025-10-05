#include <stdio.h>

int main() {
	int rY = 0, rM = 0;

	int n;
	scanf("%d", &n);
	while (n--) {
		int time;
		scanf("%d", &time);
		rY += ((time / 30 + 1) * 10);
		rM += ((time / 60 + 1) * 15);
	}

	if (rY > rM)
		printf("M %d", rM);
	else if (rY < rM)
		printf("Y %d", rY);
	else
		printf("Y M %d", rY);
	return 0;
}