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
	int* elements;
	int len;
} SCC;

#define MAX_IDX 10000
#define EMPTY -1

int v, e;
LN* adj_list[MAX_IDX + 1];
LN* rev_adj_list[MAX_IDX + 1];

bool visit[MAX_IDX + 1 + 1];
int stack[MAX_IDX + 1], top = EMPTY;

SCC list_scc[MAX_IDX];
int len_scc;
int unsorted_scc[MAX_IDX], len_unsorted_scc;

int asc_int(const void* a, const void* b) {
	if (*(int*)a > *(int*)b) {
		return 1;
	} else if (*(int*)a < *(int*)b) {
		return -1;
	} else {
		return 0;
	}
}

int asc_scc(const void* a, const void* b) {
	if (((SCC*)a)->elements[0] > ((SCC*)b)->elements[0]) {
		return 1;
	} else if (((SCC*)a)->elements[0] < ((SCC*)b)->elements[0]) {
		return -1;
	} else {
		return 0;
	}
}

void insertListNode(LN** list, int a, int b) {
	LN* newNode = (LN*)malloc(sizeof(LN));
	newNode->dst = b, newNode->next = list[a];
	list[a] = newNode;
	return;
}

void visit_init() {
	for (int i = 0; i <= v; ++i) {
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
	stack[++top] = x;
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
	return;
}

void make_scc(LN** list, int x) {
	len_unsorted_scc = 0;
	rev_dfs(list, x);
	qsort(unsorted_scc, len_unsorted_scc, sizeof(int), asc_int);

	SCC* temp = &list_scc[len_scc++];
	temp->elements = (int*)malloc(sizeof(int) * len_unsorted_scc);
	for (int i = 0; i < len_unsorted_scc; ++i) {
		temp->elements[i] = unsorted_scc[i];
	}
	temp->len = len_unsorted_scc;

	return;
}

void print_result() {
	printf("%d\n", len_scc);
	for (int i = 0; i < len_scc; ++i) {
		for (int j = 0; j < list_scc[i].len; ++j) {
			printf("%d ", list_scc[i].elements[j]);
		}
		printf("-1\n");
	}
	return;
}

int main() {
	scanf("%d %d", &v, &e);
	while (e--) {
		int a, b;
		scanf("%d %d", &a, &b);
		insertListNode(adj_list, a, b);
		insertListNode(rev_adj_list, b, a);
	}

	visit_init();
	for (int i = 1; i <= v; ++i) {
		if (visit[i] == false) {
			visit[i] = true;
			dfs(adj_list, i);
		}
	}

	visit_init();
	while (top > EMPTY) {
		int cur = stack[top--];
		if (visit[cur] == false) {
			visit[cur] = true;
			make_scc(rev_adj_list, cur);
		}
	}

	qsort(list_scc, len_scc, sizeof(SCC), asc_scc);
	print_result();
	return 0;
}