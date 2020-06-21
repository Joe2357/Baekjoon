#include <stdio.h>

typedef struct Position {	// struct for saving position and times we move
	int x, count;
} PS;

int main(n, k) {
	scanf("%d %d", &n, &k);
	int BFS[100001] = { 0 }, front = 0, rear = 1;							// using BFS
	PS queue[999999] = { {n,0} };
	while (front != rear) {
		PS temp = queue[front++];											// push to queue
		if (temp.x == k) {													// find her sister
			printf("%d", temp.count);
			return 0;
		}
		if (temp.x < 0 || temp.x > 100000 || BFS[temp.x])					// out of grid or already visited ( don't need to count )
			continue;
		else {
			BFS[temp.x] = 1;												// check visited & search next
			queue[rear].x = temp.x - 1, queue[rear++].count = ++temp.count;
			queue[rear].x = temp.x + 1, queue[rear++].count = temp.count;
			queue[rear].x = temp.x * 2, queue[rear++].count = temp.count;
		}
	}
}