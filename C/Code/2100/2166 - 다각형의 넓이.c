#include <stdio.h>

typedef long long ll;
typedef struct Node {
    ll x, y;
} ND;

#define MAX_IDX 10000
ND arr[MAX_IDX];
int n;

#define abs(x) ((x < 0) ? (-x) : (x))

double getOuterProduct(int i, int j) {
    ND a = (ND){arr[i].x - arr[0].x, arr[i].y - arr[0].y};
    ND b = (ND){arr[j].x - arr[0].x, arr[j].y - arr[0].y};

    return (double)(a.x * b.y - b.x * a.y);
}

int main() {
    int n;
    scanf("%d", &n);
    double ans = 0.0;

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
    }

    for (int i = 1; i < n - 1; ++i) {
        ans += (getOuterProduct(i, i + 1) / 2.0);
    }

    printf("%.1lf", abs(ans));
    return 0;
}