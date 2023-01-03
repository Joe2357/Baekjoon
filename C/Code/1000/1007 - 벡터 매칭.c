#include <math.h>
#include <stdio.h>

typedef struct Node {
	int x, y;
} ND;

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 20
#define INF 987654321987654321

ND arr[MAX_IDX];
bool ch[MAX_IDX + 1];
int choosed;
int n, target;
long long result, sum_x, sum_y;

#define min(a, b) (((a) > (b)) ? (b) : (a))

void init() {
	sum_x = sum_y = 0;
	result = INF;
	choosed = 0;
	return;
}

void get_result() {
	long long tx = sum_x, ty = sum_y;
	for (int i = 0; i < n; ++i) {
		if (ch[i]) {
			tx -= (arr[i].x << 1), ty -= (arr[i].y << 1);
		}
	}

	result = min(result, tx * tx + ty * ty);
	return;
}

void backtrack(int x) {
	if (choosed == target) {
		get_result();
		return;
	} else if (x == n) {
		return;
	}

	ch[x] = true;
	++choosed;
	backtrack(x + 1);

	ch[x] = false;
	--choosed;
	backtrack(x + 1);

	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();

		scanf("%d", &n);
		target = (n >> 1);
		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[i] = (ND){a, b};
			sum_x += a, sum_y += b;
		}

		backtrack(0);
		printf("%.7lf\n", sqrt(result));
	}

	return 0;
}