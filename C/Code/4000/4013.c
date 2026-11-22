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
	int sum_cash;
	bool haveRestaurant;
	LN* next;
} SCC;

#define MAX_IDX (int)(5e5)
#define NONE 0
#define EMPTY -1
const int INF = (int)(2e9 + 1);

int n, m;
int s, p;
LN* adj_list[MAX_IDX + 1];
LN* rev_adj_list[MAX_IDX + 1];

int cash[MAX_IDX + 1];
bool isRestaurant[MAX_IDX + 1 + 1];

bool visit[MAX_IDX + 1 + 1];
int arr[MAX_IDX + 1];
int top = EMPTY, front = NONE, rear = NONE;

SCC list_scc[MAX_IDX];
int len_scc;
int unsorted_scc[MAX_IDX], len_unsorted_scc;
int number_scc[MAX_IDX + 1];
int started_scc;

int deg[MAX_IDX + 1];
int dp[MAX_IDX + 1];

#define max(a, b) (((a) > (b)) ? (a) : (b))

void insertListNode(LN** list, int a, int b) {
	LN* newNode = (LN*)malloc(sizeof(LN));
	newNode->dst = b, newNode->next = list[a];
	list[a] = newNode;
	return;
}

void insertSCCEdge(LN** head, int b) {
	LN* newNode = (LN*)malloc(sizeof(LN));
	newNode->dst = b, newNode->next = *head;
	*head = newNode;
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
	temp->sum_cash = 0;
	temp->next = NULL;
	temp->haveRestaurant = false;

	for (int i = 0; i < len_unsorted_scc; ++i) {
		int c = unsorted_scc[i];
		temp->sum_cash += cash[c];
		temp->haveRestaurant |= isRestaurant[c];
	}
	return;
}

void make_scc_graph() {
	for (int i = 1; i <= n; ++i) {
		int a = number_scc[i];
		for (LN* cur = adj_list[i]; cur != NULL; cur = cur->next) {
			int b = number_scc[cur->dst];
			if (a != b) {
				insertSCCEdge(&list_scc[a].next, b);
				deg[b] += 1;
			}
		}
	}
	return;
}

void read_input() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		insertListNode(adj_list, a, b);
		insertListNode(rev_adj_list, b, a);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", cash + i);
	}
	scanf("%d %d", &s, &p);
	while (p--) {
		int x;
		scanf("%d", &x);
		isRestaurant[x] = true;
	}
	return;
}

int main() {
	read_input();

	// 1. SCC 만들기
	visit_init();
	for (int i = 1; i <= n; ++i) {
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
	started_scc = number_scc[s];

	// 3. SCC 그래프 dp 계산
	for (int i = 0; i <= n; ++i) {
		dp[i] = -INF;
	}
	int ret = NONE;
	dp[started_scc] = list_scc[started_scc].sum_cash;
	if (list_scc[started_scc].haveRestaurant == true) {
		ret = max(ret, dp[started_scc]);
	}

	for (int i = 0; i < len_scc; ++i) {
		if (deg[i] == 0) {
			arr[rear++] = i;
		}
	}

	while (front < rear) {
		int x = arr[front++];
		SCC c = list_scc[x];

		for (LN* cur = c.next; cur != NULL; cur = cur->next) {
			dp[cur->dst] = max(dp[cur->dst], dp[x] + list_scc[cur->dst].sum_cash);
			if (list_scc[cur->dst].haveRestaurant == true) {
				ret = max(ret, dp[cur->dst]);
			}

			if (--deg[cur->dst] == 0) {
				arr[rear++] = cur->dst;
			}
		}
	}

	// 4. 결과 출력
	printf("%d", ret);
	return 0;
}