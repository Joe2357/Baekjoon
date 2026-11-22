#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct ListNode {
	int dst;
	struct ListNode* next;
} LN;
typedef struct SCC {
	LN* next;
} SCC;

#define MAX_IDX (int)(1e5)
#define EMPTY -1
#define NONE 0

int n, m;
LN* adj_list[MAX_IDX + 1];
LN* rev_adj_list[MAX_IDX + 1];

bool visit[MAX_IDX + 1 + 1];
int arr[MAX_IDX]; // 다용도 (스택, 큐)
int top = EMPTY, front = NONE, rear = NONE;

SCC list_scc[MAX_IDX];
int len_scc;
int unsorted_scc[MAX_IDX], len_unsorted_scc;
int number_scc[MAX_IDX + 1];

int deg[MAX_IDX + 1];

void insertNode(LN** list, int x) {
	LN* newNode = (LN*)malloc(sizeof(LN));
	newNode->dst = x, newNode->next = *list;
	*list = newNode;
	return;
}

void init() {
	for (int i = 0; i <= n; ++i) {
		adj_list[i] = NULL;
		rev_adj_list[i] = NULL;
		deg[i] = 0;
		list_scc[i].next = NULL;
		number_scc[i] = NONE;
	}
	top = EMPTY, front = rear = NONE;
	len_scc = 0;
	return;
}

void read_input() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		insertNode(&(adj_list[x]), y);
		insertNode(&(rev_adj_list[y]), x);
	}
	return;
}

void visit_init() {
	for (int i = 0; i <= n; ++i) {
		visit[i] = false;
	}
	return;
}

void dfs(LN** list, int x) {
	for (LN* cur = list[x]; cur != NULL; cur = cur->next) {
		if (visit[cur->dst] == false) {
			visit[cur->dst] = true;
			dfs(list, cur->dst);
		}
	}
	arr[++top] = x;
	return;
}

void rev_dfs(LN** list, int x) {
	for (LN* cur = list[x]; cur != NULL; cur = cur->next) {
		if (visit[cur->dst] == false) {
			visit[cur->dst] = true;
			rev_dfs(list, cur->dst);
		}
	}
	unsorted_scc[len_unsorted_scc++] = x;
	number_scc[x] = len_scc;
	return;
}

void make_scc(LN** list, int x) {
	len_unsorted_scc = 0;
	rev_dfs(list, x);

	SCC* temp = &list_scc[len_scc++];
	temp->next = NULL;
	return;
}

void make_scc_graph() {
	for (int i = 0; i <= n; ++i) {
		int a = number_scc[i];
		for (LN* cur = adj_list[i]; cur != NULL; cur = cur->next) {
			int b = number_scc[cur->dst];
			if (a != b) {
				insertNode(&list_scc[a].next, b);
				deg[b] += 1;
			}
		}
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		read_input();

		// 1. SCC 만들기
		visit_init();
		for (int i = 0; i < n; ++i) {
			if (visit[i] == false) {
				visit[i] = true;
				dfs(adj_list, i);
			}
		}
		visit_init();
		while (top > EMPTY) {
			int cur = arr[top--];
			if (visit[cur] == false) {
				visit[cur] = true;
				make_scc(rev_adj_list, cur);
			}
		}

		// 2. SCC 그래프 제작 및 전처리
		make_scc_graph();

		// 3. deg = 0인 갯수 계산
		int zero_deg_idx = EMPTY;
		bool hasMultipleZeroDegree = false;
		for (int i = 0; i < len_scc; ++i) {
			if (deg[i] == 0) {
				if (zero_deg_idx != EMPTY) {
					hasMultipleZeroDegree = true;
					break;
				} else {
					zero_deg_idx = i;
				}
			}
		}

		// 4. 결과 출력
		if (hasMultipleZeroDegree == true) {
			printf("Confused\n");
		} else {
			for (int i = 0; i < n; ++i) {
				if (number_scc[i] == zero_deg_idx) {
					printf("%d\n", i);
				}
			}
		}
		printf("\n");
	}
	return 0;
}