#include <stdio.h>

typedef struct Position {
	int x, y, count;
} PS;

int main(n, m) {
	char arr[100][101];
	int visited[100][101] = {0}, front = 0, rear = 1;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) // input grid
		scanf("%s", arr[i]);
	PS queue[100000] = {{0, 0, 1}}; // start point
	while (front != rear) {
		PS temp = queue[front++];
		if (temp.x == m - 1 && temp.y == n - 1) { // if end point
			printf("%d", temp.count);			  // print result
			return 0;
		} else if (temp.x < 0 || temp.y < 0 || temp.x == m || temp.y == n || arr[temp.y][temp.x] == '0' || visited[temp.y][temp.x]) // out of grid or already visited
			continue;
		else {																						// BFS
			visited[temp.y][temp.x] = 1;															// check visited
			queue[rear].y = temp.y - 1, queue[rear].x = temp.x, queue[rear++].count = ++temp.count; // plus 1 to count ( room passed ) / down
			queue[rear].y = temp.y + 1, queue[rear].x = temp.x, queue[rear++].count = temp.count;	// up
			queue[rear].y = temp.y, queue[rear].x = temp.x - 1, queue[rear++].count = temp.count;	// left
			queue[rear].y = temp.y, queue[rear].x = temp.x + 1, queue[rear++].count = temp.count;	// right
		}
	}
}