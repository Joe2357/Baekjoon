#include <stdio.h>
#define abs(x) ((x) < 0 ? (-(x)) : (x))

typedef char boolean;
#define True 1
#define False 0

#define M_I 15000
#define M_W 30
boolean canWeight[M_W + 1][M_I + 1] = { False };
int weight[M_W]; int n;

void knapsack(int item, int cap) {

	if (item > n || canWeight[item][cap])
		return;

	canWeight[item][cap] = True;

	knapsack(item + 1, cap + weight[item]);
	knapsack(item + 1, cap);
	knapsack(item + 1, abs(cap - weight[item]));

	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", weight + i);
	}
	knapsack(0, 0);

	int m;
	scanf("%d", &m);
	while (m--) {
		int a;
		scanf("%d", &a);
		if (a > M_I)
			printf("N ");
		else
			printf("%c ", 'N' + ('Y' - 'N') * canWeight[n][a]);
	}

	return 0;
}