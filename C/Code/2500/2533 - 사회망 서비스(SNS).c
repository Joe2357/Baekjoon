#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x;
	struct Node* next;
} ND;

#define M (int)1e6
const int START = 1, VOID = 0;
const int NOT_EARLY = 0, EARLY = 1;

ND* matrix[M + 1];
int dp[M + 1][2];
int n;

#define min(a, b) (((a) > (b)) ? (b) : (a))
ND* createNewNode(int v) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->x = v;
	newNode->next = NULL;
	return newNode;
}

void insert(int a, int b) {
	if (matrix[a] == NULL) {
		matrix[a] = createNewNode(b);
	} else {
		ND* newNode = createNewNode(b);
		newNode->next = matrix[a];
		matrix[a] = newNode;
	}
	return;
}

void process(int x, int p) {
	//printf("t : %d %d\n", x, p);
	ND* cur = matrix[x];
	dp[x][EARLY] = 1;
	while (cur) {
		if (cur->x != p) {
			process(cur->x, x);
			dp[x][NOT_EARLY] += dp[cur->x][EARLY];
			dp[x][EARLY] += min(dp[cur->x][NOT_EARLY], dp[cur->x][EARLY]);
		}
		cur = cur->next;
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		insert(a, b), insert(b, a);
	}

	process(START, VOID);
	printf("%d", min(dp[START][NOT_EARLY], dp[START][EARLY]));
	return 0;
}