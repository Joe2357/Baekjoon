#include <stdio.h>

#define MAX_LEN (int)2e5 + 3
#define INF 987654321

typedef char boolean;
#define True 1
#define False 0
typedef struct Node {
	int idx;
	int vle;
} ND;

boolean visited[MAX_LEN + 1];
int dp[MAX_LEN + 1];
int n, k;
ND queue[MAX_LEN];
int front, rear;
int retval[MAX_LEN + 1];
int len;

int main() {
	scanf("%d %d", &n, &k);
	queue[0] = (ND) { n, 0 };
	rear = 1;
	visited[n] = True;

	for (int i = 0; i <= MAX_LEN; ++i) {
		dp[i] = INF;
	}

	while (front != rear) {
		ND node = queue[front++];
		dp[node.idx] = node.vle;

		if (node.idx == k) {
			break;
		}

		int a = node.idx - 1,
			b = node.idx + 1,
			c = node.idx << 1;

		if (a >= 0 && a <= MAX_LEN && !visited[a]) {
			visited[a] = True;
			queue[rear++] = (ND) { a, node.vle + 1 };
		}
		if (b <= MAX_LEN && !visited[b]) {
			visited[b] = True;
			queue[rear++] = (ND) { b, node.vle + 1 };
		}
		if (c <= MAX_LEN && !visited[c]) {
			visited[c] = True;
			queue[rear++] = (ND) { c, node.vle + 1 };
		}
	}

	len = dp[k];
	printf("%d\n", len);
	retval[len] = k;
	for (int a = len - 1, b = k; a >= 0;) {
		if (((b & 1) == 0) && (dp[b >> 1] == a)) {
			b >>= 1;
			retval[a--] = b;
		}
		else if (b + 1 <= MAX_LEN && dp[b + 1] == a) {
			retval[a--] = ++b;
		}
		else {
			retval[a--] = --b;
		}
	}

	for (int i = 0; i <= len; ++i) {
		printf("%d ", retval[i]);
	}
	return 0;
}