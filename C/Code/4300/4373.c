#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_IDX 1000
const int NONE = -1;

typedef struct Node {
	int idx1, idx2;
	int v;
} Node;

int arr[MAX_IDX];
int n;
Node node[MAX_IDX * MAX_IDX];
int l;

int array_asc(const void* a, const void* b) {
	int n1 = *(int*)a, n2 = *(int*)b;

	if (n1 > n2) {
		return 1;
	} else if (n1 < n2) {
		return -1;
	} else {
		return 0;
	}
}
int node_asc(const void* a, const void* b) {
	Node *n1 = (Node*)a, *n2 = (Node*)b;

	if (n1->v > n2->v) {
		return 1;
	} else if (n1->v < n2->v) {
		return -1;
	} else {
		return 0;
	}
}

void read_array() {
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	return;
}

// 가능한 a + b를 먼저 계산
void preprocess() {
	qsort(arr, n, sizeof(int), array_asc);
	l = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			node[l++] = (Node){i, j, arr[i] + arr[j]};
		}
	}
	qsort(node, l, sizeof(Node), node_asc);
	return;
}

int find(int target) {
	int low = 0;
	int high = l - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (node[mid].v == target) {
			return mid;
		} else if (node[mid].v < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return NONE;
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}

		read_array();
		preprocess();

		bool isAnswerExists = false;
		for (int i = n - 1; i >= 0; --i) { // 가능한 큰 d부터 찾아야함
			isAnswerExists = false;

			for (int j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}

				int target = arr[i] - arr[j]; // d - c
				int idx = find(target);		  // node 배열에서 a + b = d - c인 지점 찾기

				if (idx == NONE) { // 같은 지점이 없다면
					continue;
				} else { // 있으면, 현재 지점과 옆 지점들을 비교해야함 (각 원소는 달라도 합이 같을 수는 있음)
					for (int t1 = idx; t1 < l; ++t1) {
						if (node[t1].v == node[idx].v) {
							if (node[t1].idx1 != i && node[t1].idx1 != j && node[t1].idx2 != i && node[t1].idx2 != j) {
								isAnswerExists = true;
								break;
							}
						} else {
							break;
						}
					}
					for (int t1 = idx - 1; isAnswerExists == false && t1 >= 0; --t1) {
						if (node[t1].v == node[idx].v) {
							if (node[t1].idx1 != i && node[t1].idx1 != j && node[t1].idx2 != i && node[t1].idx2 != j) {
								isAnswerExists = true;
								break;
							}
						} else {
							break;
						}
					}
				}

				if (isAnswerExists == true) {
					break;
				}
			}

			if (isAnswerExists == true) {
				printf("%d\n", arr[i]);
				break;
			}
		}

		if (isAnswerExists == false) {
			printf("no solution\n");
		}
	}
	return 0;
}