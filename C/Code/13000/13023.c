#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_PEOPLE 2000
#define TARGET_DEGREE 4

// 인접리스트 구현
typedef struct Node {
	int idx;
	struct Node* next;
} ND;
ND* adjency_list[MAX_PEOPLE];
ND* createNewNode(int x) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->idx = x, newNode->next = NULL;
	return newNode;
}
void make_connection(int a, int b) {
	ND* newNode = createNewNode(a);
	newNode->next = adjency_list[b];
	adjency_list[b] = newNode;
	return;
}

int n, m;

bool dfs(bool* visit, int x, int depth) {
	if (depth == TARGET_DEGREE) {
		return true;
	} else {
		bool result = false;
		ND* current_ptr = adjency_list[x];
		for (ND* current_ptr = adjency_list[x]; current_ptr != NULL; current_ptr = current_ptr->next) {
			if (visit[current_ptr->idx] == false) {
				visit[current_ptr->idx] = true;
				result |= dfs(visit, current_ptr->idx, depth + 1);
				visit[current_ptr->idx] = false;
			}
		}
		return result;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		make_connection(a, b);
		make_connection(b, a);
	}

	// 한번이라도 깊이가 4 이상이 된다면 true
	bool visit[MAX_PEOPLE + 1] = {false};
	bool isAnswerExists = false;
	for (int i = 0; isAnswerExists == false && i < n; ++i) {
		visit[i] = true;
		isAnswerExists |= dfs(visit, i, 0);
		visit[i] = false;
	}

	printf("%d", isAnswerExists);
	return 0;
}