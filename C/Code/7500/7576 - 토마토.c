#include <stdio.h>
#define max(a, b) a > b ? a : b
#define QUEUE_SIZE 10000

typedef struct Position {
	int x, y, day;
} PS;

PS Queue[QUEUE_SIZE];
int arr[1000][1000],
	front = -1, rear = 0,
	n, m, tomato[2];

void change(int y, int x, int day) {
	if (x < 0 || y < 0 || x == n || y == m) // out of grid
		return;
	if (!arr[y][x]) { // if not visited
		tomato[0]--, tomato[1]++;
		arr[y][x] = day + 1;
		Queue[rear].x = x, Queue[rear].y = y, Queue[rear].day = day + 1,
			rear++, rear %= QUEUE_SIZE;
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (!arr[i][j])
				tomato[0]++;
			else if (arr[i][j] == 1) { // BFS queue expression
				tomato[1]++;
				Queue[rear].x = j, Queue[rear].y = i, Queue[rear].day = 0,
					rear++, rear %= QUEUE_SIZE;
			}
		}
	while (front != rear && tomato[0]) { // BFS search
		PS temp = Queue[++front];
		change(temp.y - 1, temp.x, temp.day);
		change(temp.y + 1, temp.x, temp.day);
		change(temp.y, temp.x - 1, temp.day);
		change(temp.y, temp.x + 1, temp.day);
	}
	if (!tomato[0]) { // no tomato left
		if (front == -1)
			printf("0"); // there's no tomato[0]
		else {
			int result = -1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					result = max(arr[i][j], result); // find the largest value
			printf("%d", result);
		}
	}
	else // can't make all tomatoes to 1
		printf("-1");
	return 0;
}