#include <stdio.h>
#define PEOPLE 100

typedef struct Position {
	int end, count;
} PS;

int getParent[PEOPLE][PEOPLE],
visited[PEOPLE];

int main(m) {
	int person;
	scanf("%d", &person);
	int targetX, targetY;
	scanf("%d %d", &targetX, &targetY);
	targetX--, targetY--;
	for (scanf("%d", &m); m; m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		getParent[--a][--b] = 1,
			getParent[b][a] = 1;
	}
	// BFS search
	PS queue[PEOPLE] = { 0 };
	int front = 0, rear = 0;
	for (int i = 0; i < person; i++)
		if (getParent[targetX][i])
			queue[rear].end = i, queue[rear++].count = 1;
	visited[targetX] = 1;
	while (front != rear) {
		PS temp = queue[front++];
		// route found
		if (temp.end == targetY) {
			printf("%d", temp.count);
			return 0;
		}
		else if (visited[temp.end]) // already visited
			continue;
		// add to queue
		for (int i = 0; i < person; i++)
			if (getParent[temp.end][i])
				queue[rear].end = i, queue[rear++].count = temp.count + 1;
		visited[temp.end] = 1;
	}
	// no way
	printf("-1");
	return 0;
}