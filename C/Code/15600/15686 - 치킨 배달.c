#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define abs(x) (((x) < 0) ? (-(x)) : (x))

#define N 50
#define MAX_LEN 100
#define M 13
#define INF 987654321

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} PS;

PS house[MAX_LEN]; int house_len;
PS chicken[M]; int chicken_len;
int result = INF;
int n, m;

int getLength(PS a, PS b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int getResult(bool* arr) {
	int tempResult = 0;
	for (int i = 0; i < house_len; ++i) {
		int tempCase = INF;
		for (int j = 0; j < chicken_len; ++j) {
			if (arr[j]) {
				tempCase = min(tempCase, getLength(house[i], chicken[j]));
			}
		}
		tempResult += tempCase;
	}
	return tempResult;
}

void backtrack(bool* arr, int cur, int used) {
	if (used == m) {
		result = min(result, getResult(arr));
		return;
	}
	for (int i = cur; i < chicken_len; ++i) {
		arr[i] = true;
		backtrack(arr, i + 1, used + 1);
		arr[i] = false;
	}
	return;
}

void solve() {
	bool choose[M + 1] = { false };
	backtrack(choose, 0, 0);
	return;
}

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			#define HOUSE 1
			#define CHICKEN 2
			int a;
			scanf("%d", &a);
			switch (a) {
				case HOUSE:
					house[house_len++] = (PS) { i, j };
					break;
				case CHICKEN:
					chicken[chicken_len++] = (PS) { i, j };
					break;
			}
		}
	}
	return;
}
int main() {
	read_input();
	solve();
	printf("%d", result);
	return 0;
}