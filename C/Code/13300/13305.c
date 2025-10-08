#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

typedef long long LLD;

int main() {
	int n;
	LLD result = 0;

#define MAX_INDEX (int)1e6
	LLD distance[MAX_INDEX] = {0};
#define INF (LLD)1e10
	LLD minValue = INF;

	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%lld", distance + i);
	}
	for (int i = 0; i < n - 1; ++i) {
		LLD a;
		scanf("%lld", &a);
		minValue = min(minValue, a);
		result += (minValue * distance[i]);
	}

	printf("%lld", result);
	return 0;
}