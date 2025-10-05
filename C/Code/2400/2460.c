#include <stdio.h>

const int MAX_STATION = 10;
const int NONE = -1;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	int people = 0, ret = NONE;
	for (int i = 0; i < MAX_STATION; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		people += (b - a);
		ret = max(ret, people);
	}
	printf("%d", ret);
	return 0;
}