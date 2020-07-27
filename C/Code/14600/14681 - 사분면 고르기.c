#include <stdio.h>

int main() {
	int x, y, result = 0;
	scanf("%d %d", &x, &y);
	if (x > 0)
		result += 2;
	if (y > 0)
		result++;
	switch (result) {
		case 0:
			printf("3");
			break;
		case 1:
			printf("2");
			break;
		case 2:
			printf("4");
			break;
		case 3:
			printf("1");
			break;
	}
	return 0;
}