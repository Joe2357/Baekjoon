#include <stdio.h>

typedef struct Node {
	unsigned int num[4];
	int mod;
	int len;
} ND;
typedef char boolean;
#define True 1
#define False 0

#define MAX_IDX 20000

FILE* fp;

void makeString(unsigned int* arr, int len) {
	char str[100 + 1];
	int x = 0;
	for (int i = 0; i < 4 && x < len; ++i) {
		for (int j = 0; j < 32 && x < len; ++j) {
			str[x++] = '0' + ((arr[i] & (1 << j)) > 0);
		}
	}
	str[len] = '\0';
	printf("%s\n", str);
	return;
}

void make(int x) {
	ND queue[MAX_IDX + 1] = { {{1,0,0,0}, 1, 1 } };
	int front = 0, rear = 1;
	boolean visited[MAX_IDX + 2] = { False, True };
	while (front < rear) {
		ND node = queue[front++];

		if (node.mod % x == 0) {
			makeString(node.num, node.len);
			return;
		}

		int m = (node.mod * 10) % x,
			a = node.len / 32, b = node.len % 32;

		if (!visited[m]) {
			visited[m] = True;
			for (int i = 0; i < 4; ++i) {
				queue[rear].num[i] = node.num[i];
			}
			queue[rear].mod = m;
			queue[rear].len = node.len + 1;
			++rear;
		}
		if (!visited[m + 1]) {
			visited[m + 1] = True;
			for (int i = 0; i < 4; ++i) {
				queue[rear].num[i] = node.num[i];
			}
			queue[rear].num[a] |= (1 << b);
			queue[rear].mod = m + 1;
			queue[rear].len = node.len + 1;
			++rear;
		}
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		make(n);
	}
	return 0;
}