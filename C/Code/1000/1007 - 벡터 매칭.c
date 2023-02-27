#include <math.h>  // sqrt
#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	long long x, y;
} ND;

#define INF 987654321987654321
#define MAX_IDX 20
ND arr[MAX_IDX];
bool comb[MAX_IDX];
int n;
long long result;
int threshold;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define get_len(a) ((a.x * a.x) + (a.y * a.y))

void reset() {
	for (int i = 0; i < n; ++i) {
		comb[i] = false;
	}
	result = INF;
	return;
}

void get_current_result() {
	ND vector_sum = (ND){0, 0};

	// if choosed, add them all
	// if not choosed, subtract them all
	for (int i = 0; i < n; ++i) {
		if (comb[i] == true) {
			vector_sum.x += arr[i].x;
			vector_sum.y += arr[i].y;
		} else {
			vector_sum.x -= arr[i].x;
			vector_sum.y -= arr[i].y;
		}
	}

	// calculate vector length
	result = min(result, get_len(vector_sum));
	return;
}

void make_combination(int cur, int choose_count) {
	if (choose_count == threshold) {  // combination created
		get_current_result();
		return;
	} else if (cur == n) {	// out of bound
		return;
	}

	// backtracking
	comb[cur] = true;
	make_combination(cur + 1, choose_count + 1);

	comb[cur] = false;
	make_combination(cur + 1, choose_count);

	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		reset();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			arr[i] = (ND){x, y};
		}

		threshold = (n >> 1);
		make_combination(0, 0);

		printf("%.7lf\n", sqrt(result));
	}
	return 0;
}