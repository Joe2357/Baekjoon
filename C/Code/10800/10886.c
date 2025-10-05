#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int cute = 0, not_cute = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		cute += (x == 1);
		not_cute += (x == 0);
	}

	if (cute < not_cute) {
		printf("Junhee is not cute!");
	} else {
		printf("Junhee is cute!");
	}
	return 0;
}