#include <stdio.h>

#define RED 0
#define GREEN 1
#define BLUE 2
typedef struct Node {
	int value[3][3];
} ND;

#define MAX_LEN 1000
ND dp[MAX_LEN + 1];
int n;

#define min(a, b) (((a) > (b)) ? (b) : (a))
int getMinValue(ND a) {
	int r = min(a.value[RED][GREEN], a.value[RED][BLUE]);
	int g = min(a.value[GREEN][RED], a.value[GREEN][BLUE]);
	int b = min(a.value[BLUE][RED], a.value[BLUE][GREEN]);

	return min(r, min(g, b));
}

#define INF 987654321
int main() {
	scanf("%d", &n);
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	dp[1] = (ND) {
		a, INF, INF,
		INF, b, INF,
		INF, INF, c
	};
	for (int i = 2; i <= n; ++i) {
		int red, green, blue;
		scanf("%d %d %d", &red, &green, &blue);

		dp[i].value[RED][RED] = min(dp[i - 1].value[RED][GREEN], dp[i - 1].value[RED][BLUE]) + red;
		dp[i].value[RED][GREEN] = min(dp[i - 1].value[RED][RED], dp[i - 1].value[RED][BLUE]) + green;
		dp[i].value[RED][BLUE] = min(dp[i - 1].value[RED][RED], dp[i - 1].value[RED][GREEN]) + blue;

		dp[i].value[GREEN][RED] = min(dp[i - 1].value[GREEN][GREEN], dp[i - 1].value[GREEN][BLUE]) + red;
		dp[i].value[GREEN][GREEN] = min(dp[i - 1].value[GREEN][RED], dp[i - 1].value[GREEN][BLUE]) + green;
		dp[i].value[GREEN][BLUE] = min(dp[i - 1].value[GREEN][RED], dp[i - 1].value[GREEN][GREEN]) + blue;

		dp[i].value[BLUE][RED] = min(dp[i - 1].value[BLUE][GREEN], dp[i - 1].value[BLUE][BLUE]) + red;
		dp[i].value[BLUE][GREEN] = min(dp[i - 1].value[BLUE][RED], dp[i - 1].value[BLUE][BLUE]) + green;
		dp[i].value[BLUE][BLUE] = min(dp[i - 1].value[BLUE][RED], dp[i - 1].value[BLUE][GREEN]) + blue;
	}

	printf("%d", getMinValue(dp[n]));
	return 0;
}