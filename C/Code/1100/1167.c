#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int dest;
	int weight;
	struct Node* next;
} ND;

#define MAX_INDEX (int)1e5

ND* link[MAX_INDEX];
int n;
int w[MAX_INDEX];

#define max(a, b) (((a) > (b)) ? (a) : (b))

ND* createNewNode(int d, int v) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->dest = d;
	newNode->weight = v;
	newNode->next = NULL;
	return newNode;
}

void connect(int s, int d, int v) {
	ND* newNode = createNewNode(d, v);
	newNode->next = link[s];
	link[s] = newNode;
	return;
}

void dfs(int x) {
	ND* ptr = link[x];
	while (ptr != NULL) {
		if (w[ptr->dest] == -1) {
			w[ptr->dest] = w[x] + ptr->weight;
			dfs(ptr->dest);
		}
		ptr = ptr->next;
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		int b, c;
		for (scanf("%d", &b); b != -1; scanf("%d", &b)) {
			scanf("%d", &c);
			connect(a - 1, b - 1, c);
		}
		w[a - 1] = -1;
	}

	w[0] = 0;
	dfs(0);

	int s = 0;
	for (int i = 1; i < n; ++i) {
		if (w[s] < w[i]) {
			s = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		w[i] = -1 * (i != s);
	}

	dfs(s);
	int result = -1;
	for (int i = 0; i < n; ++i) {
		result = max(result, w[i]);
	}
	printf("%d", result);
	return 0;
}