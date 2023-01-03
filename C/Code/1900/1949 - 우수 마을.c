#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x;
	struct Node* next;
} ND;

#define M (int)1e4
#define INF -123456789
const int START = 1, VOID = 0;
const int NOT_DIDNT = 0, NOT_DID = 1, YES = 2;

ND* matrix[M + 1];
int arr[M + 1];
int dp[M + 1][3];
int n;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
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
	dp[x][YES] = arr[x];

	ND* cur = matrix[x];
	int temp, tempMax = INF;
	while (cur) {
		if (cur->x != p) {
			process(cur->x, x);
			temp = max(dp[cur->x][NOT_DIDNT], dp[cur->x][NOT_DID]);

			dp[x][NOT_DIDNT] += dp[cur->x][NOT_DID];
			dp[x][NOT_DID] += temp, tempMax = max(tempMax, dp[cur->x][YES] - temp);
			if (dp[cur->x][YES] - temp > 0) {
				dp[x][NOT_DID] += (dp[cur->x][YES] - temp);
			}
			dp[x][YES] += temp;
		}
		cur = cur->next;
	}
	if (tempMax != INF && temp < 0) {
		dp[x][NOT_DID] += tempMax;
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		insert(a, b), insert(b, a);
	}

	process(START, VOID);
	printf("%d", max(max(dp[START][NOT_DIDNT], dp[START][NOT_DID]), dp[START][YES]));
	return 0;
}