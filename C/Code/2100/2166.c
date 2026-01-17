#include <stdio.h>

typedef long long ll;
typedef struct Node {
	ll x, y;
} ND;

#define FIRST 0
#define MAX_IDX 10000

ND arr[MAX_IDX];
int n;

#define abs(x) (((x) < 0) ? (-(x)) : (x))

double getOuterProduct(int i, int j) {
	ND a = (ND){arr[i].x - arr[FIRST].x, arr[i].y - arr[FIRST].y};
	ND b = (ND){arr[j].x - arr[FIRST].x, arr[j].y - arr[FIRST].y};
	return (double)(a.x * b.y - b.x * a.y);
}

int main() {
	scanf("%d", &n);
	scanf("%lld %lld", &arr[FIRST].x, &arr[FIRST].y);
	scanf("%lld %lld", &arr[1].x, &arr[1].y);

	double ans = 0.0;
	for (int i = 2; i < n; ++i) {
		scanf("%lld %lld", &arr[i].x, &arr[i].y);
		ans += (getOuterProduct(i - 1, i) / 2.0);
	}

	printf("%.1lf", abs(ans));
	return 0;
}