#include <stdio.h>

const int MAX_POINT_PER_SHOT = 3;

int main() {
	int apple = 0, banana = 0;

	for (int i = MAX_POINT_PER_SHOT; i > 0; --i) {
		int x;
		scanf("%d", &x);
		apple += x * i;
	}
	for (int i = MAX_POINT_PER_SHOT; i > 0; --i) {
		int x;
		scanf("%d", &x);
		banana += x * i;
	}

	if (apple > banana) {
		printf("A");
	} else if (apple < banana) {
		printf("B");
	} else {
		printf("T");
	}
	return 0;
}