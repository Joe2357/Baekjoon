#include <stdio.h>

typedef struct Node {
	int minV;
	int maxV;
} ND;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
int main() {
	ND ret[3];
	int n;
	scanf("%d", &n);

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	ret[0] = (ND){a, a}, ret[1] = (ND){b, b}, ret[2] = (ND){c, c};

	ND temp[3];
	for (int i = 1; i < n; ++i) {
		scanf("%d %d %d", &a, &b, &c);

		temp[0] = (ND){min(ret[0].minV, ret[1].minV) + a, max(ret[0].maxV, ret[1].maxV) + a};
		temp[1] = (ND){min(min(ret[0].minV, ret[1].minV), ret[2].minV) + b, max(max(ret[0].maxV, ret[1].maxV), ret[2].maxV) + b};
		temp[2] = (ND){min(ret[1].minV, ret[2].minV) + c, max(ret[1].maxV, ret[2].maxV) + c};

		ret[0] = temp[0], ret[1] = temp[1], ret[2] = temp[2];
	}

	printf("%d %d", max(max(ret[0].maxV, ret[1].maxV), ret[2].maxV), min(min(ret[0].minV, ret[1].minV), ret[2].minV));
	return 0;
}