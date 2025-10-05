#include <stdio.h>

#define MAX_IDX 6
const int HAVE = 1000;
const int unit[MAX_IDX] = {500, 100, 50, 10, 5, 1};

int main() {
	int cost;
	scanf("%d", &cost);

	int remainder = HAVE - cost;
	int ret = 0;

	for (int i = 0; i < MAX_IDX; ++i) {
		ret += (remainder / unit[i]);
		remainder %= unit[i];
	}
	printf("%d", ret);
	return 0;
}