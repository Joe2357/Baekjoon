#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct TrustRelation {
	int fromIdx, toIdx;
} TrustRelation;
typedef struct AdjustmentGrid {
	int nodeCnt;
	int* nodeIdxArr;
} AdjustmentGrid;

#define MAX_IDX 10000
#define MAX_INPUT 100000

bool visit[MAX_IDX + 1 + 1];
int canDefect[MAX_IDX + 1];
AdjustmentGrid grid[MAX_IDX + 1];
int n, m;

TrustRelation input[MAX_INPUT];

int queue[MAX_IDX + 1];
int front, rear;

#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		input[i] = (TrustRelation){b, a};
	}
	return;
}

int from_asc(const void* a, const void* b) {
	TrustRelation* relA = (TrustRelation*)a;
	TrustRelation* relB = (TrustRelation*)b;
	return relA->fromIdx - relB->fromIdx;
}

void preprocess() {
	qsort(input, m, sizeof(TrustRelation), from_asc);

	int current_index = input[0].fromIdx;
	int current_length = 1;
	for (int i = 1; i < m; ++i) {
		if (current_index < input[i].fromIdx) {
			grid[current_index].nodeCnt = current_length;
			grid[current_index].nodeIdxArr = (int*)malloc(sizeof(int) * current_length);
			int arrIdx = 0;
			for (int j = i - current_length; j < i; ++j) {
				grid[current_index].nodeIdxArr[arrIdx++] = input[j].toIdx;
			}

			current_index = input[i].fromIdx;
			current_length = 1;
		} else {
			++current_length;
		}
	}

	grid[current_index].nodeCnt = current_length;
	grid[current_index].nodeIdxArr = (int*)malloc(sizeof(int) * current_length);
	int arrIdx = 0;
	for (int j = m - current_length; j < m; ++j) {
		grid[current_index].nodeIdxArr[arrIdx++] = input[j].toIdx;
	}
	return;
}

int solve(int x) {
	for (int i = 1; i <= n; ++i) {
		visit[i] = false;
	}
	front = rear = 0;

	visit[x] = true;
	queue[rear++] = x;

	while (front < rear) {
		int curr = queue[front++];
		AdjustmentGrid* adj = &grid[curr];
		for (int i = 0; i < adj->nodeCnt; ++i) {
			int next = adj->nodeIdxArr[i];
			if (visit[next] == false) {
				visit[next] = true;
				queue[rear++] = next;
			}
		}
	}
	return rear;
}

int main() {
	read_input();
	preprocess();

	int max_defect = 0;
	for (int i = 1; i <= n; ++i) {
		canDefect[i] = solve(i);
		max_defect = max(max_defect, canDefect[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (canDefect[i] == max_defect) {
			printf("%d ", i);
		}
	}
	return 0;
}