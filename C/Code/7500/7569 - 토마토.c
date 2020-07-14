#include <stdio.h>
#define QUEUE_SIZE 1000000

typedef struct Tomato {
	int x, y, z, day;
} TM;

int arr[100][100][100],
zeroCount,
front, rear,
x, y, z;
TM queue[QUEUE_SIZE];

TM pos[6] = { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1} };

int main() {
	scanf("%d %d %d", &x, &y, &z);
	// first init brute force
	for (int i = 0; i < z; i++)
		for (int j = 0; j < y; j++)
			for (int k = 0; k < x; k++) {
				int temp;
				scanf("%d", &temp);
				arr[k][j][i] = temp;
				zeroCount += !temp;
				if (temp == 1)
					for (int a = 0; a < 6; a++) { // BFS
						TM tempStruct = { k + pos[a].x, j + pos[a].y, i + pos[a].z, 1 };
						queue[rear++] = tempStruct;
						rear %= QUEUE_SIZE;
					}
			}
	// circular queue expression
	while (front != rear) {
		TM temp = queue[front++];
		front %= QUEUE_SIZE;
		// out of range
		if (temp.x < 0 || temp.y < 0 || temp.z < 0 || temp.x == x || temp.y == y || temp.z == z)
			continue;
		// already visited
		else if (arr[temp.x][temp.y][temp.z])
			continue;
		// check visited
		zeroCount--, arr[temp.x][temp.y][temp.z] = 1;
		if (!zeroCount) { // no more original tomatoes
			printf("%d", temp.day);
			return 0;
		}
		for (int a = 0; a < 6; a++) { // BFS
			TM tempStruct = { temp.x + pos[a].x, temp.y + pos[a].y, temp.z + pos[a].z, temp.day + 1 };
			queue[rear++] = tempStruct;
			rear %= QUEUE_SIZE;
		}
	}
	// 0 if no original tomato, else 1
	printf("%d", -1 * (zeroCount != 0));
	return 0;
}