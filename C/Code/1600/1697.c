#include <stdio.h>

typedef struct Position {
	int x, count;
} PS;

int main(n, k) {
	scanf("%d %d", &n, &k);
	int BFS[100001] = {0}, front = 0, rear = 1;
	PS queue[999999] = {{n, 0}};
	while (front != rear) {
		PS temp = queue[front++];
		if (temp.x == k) {
			printf("%d", temp.count);
			return 0;
		}
		if (temp.x < 0 || temp.x > 100000 || BFS[temp.x])
			continue;
		else {
			BFS[temp.x] = 1;
			queue[rear].x = temp.x - 1, queue[rear++].count = ++temp.count;
			queue[rear].x = temp.x + 1, queue[rear++].count = temp.count;
			queue[rear].x = temp.x * 2, queue[rear++].count = temp.count;
		}
	}
}