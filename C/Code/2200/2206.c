#include <stdio.h>

typedef struct Position
{
	int y, x, brk, day;
} PS;

int n, m,
	front, rear = 1;
char grid[1000][1001],
	visited[1000][1001][2];

void BFS()
{
	PS queue[1000000];
	queue[0].y = 0,
	queue[0].x = 0,
	queue[0].brk = 0,
	queue[0].day = 1;
	while (front != rear)
	{
		PS temp = queue[front++];
        front %= 1000000;
		if (temp.x == m - 1 && temp.y == n - 1)
		{
			printf("%d", temp.day);
			return;
		}
		else if (temp.x < 0 || temp.y < 0 || temp.x == m || temp.y == n || visited[temp.y][temp.x][temp.brk])
			;
		else if (temp.brk + grid[temp.y][temp.x] < '2')
		{
			visited[temp.y][temp.x][temp.brk] = 1,
			temp.day++;

			queue[rear].y = temp.y - 1,
			queue[rear].x = temp.x,
			queue[rear].brk = temp.brk + grid[temp.y][temp.x] - '0',
			queue[rear].day = temp.day,
			rear++,rear %= 1000000;

			queue[rear].y = temp.y + 1,
			queue[rear].x = temp.x,
			queue[rear].brk = temp.brk + grid[temp.y][temp.x] - '0',
			queue[rear].day = temp.day,
			rear++,rear %= 1000000;

			queue[rear].y = temp.y,
			queue[rear].x = temp.x - 1,
			queue[rear].brk = temp.brk + grid[temp.y][temp.x] - '0',
			queue[rear].day = temp.day,
			rear++,rear %= 1000000;

			queue[rear].y = temp.y,
			queue[rear].x = temp.x + 1,
			queue[rear].brk = temp.brk + grid[temp.y][temp.x] - '0',
			queue[rear].day = temp.day,
			rear++,rear %= 1000000;
		};
	}
	printf("-1");
	return;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", grid[i]);
	BFS();
	return 0;
}