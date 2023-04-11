#include <stdio.h>

typedef long long ll;
typedef struct Node {
	ll x, y;
} ND;

#define MAX_IDX 10000
ND arr[MAX_IDX];
int n;

#define abs(x) (((x) < 0) ? (-(x)) : (x))

double getOuterProduct(int i, int j) {
#define FIRST 0
	ND a = (ND){arr[i].x - arr[FIRST].x, arr[i].y - arr[FIRST].y};
	ND b = (ND){arr[j].x - arr[FIRST].x, arr[j].y - arr[FIRST].y};
	return (double)(a.x * b.y - b.x * a.y);
}

int main() {
	scanf("%d", &n);
	double ans = 0.0;
	scanf("%lld %lld", &arr[0].x, &arr[0].y);
	scanf("%lld %lld", &arr[1].x, &arr[1].y);

	for (int i = 2; i < n; ++i) {
		scanf("%lld %lld", &arr[i].x, &arr[i].y);
		ans += (getOuterProduct(i - 1, i) / 2.0);
	}

	printf("%.1lf", abs(ans));
	return 0;
}