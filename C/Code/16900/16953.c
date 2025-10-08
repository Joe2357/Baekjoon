#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;
typedef struct Node {
	ll x;
	int c;
} ND;

ll a, b;
#define MAX (int)1e5
ND queue[MAX];
int front, rear;

int main() {
	scanf("%lld %lld", &a, &b);
	queue[rear++] = (ND){a, 1};

	bool isAnswerExists = false;
	while (front != rear) {
		ND node = queue[front++];
		front %= MAX;

		if (node.x == b) {
			printf("%d", node.c);
			isAnswerExists = true;
			break;
		} else if (node.x < b) {
			queue[rear++] = (ND){node.x << 1, node.c + 1};
			rear %= MAX;
			queue[rear++] = (ND){node.x * 10 + 1, node.c + 1};
			rear %= MAX;
		}
	}

	if (!isAnswerExists) {
		printf("-1");
	}
	return 0;
}