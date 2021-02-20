#include <stdio.h>

typedef struct Node {
	int x, y;
	int moved;
} ND;

typedef char boolean;
#define True 1
#define False 0

#define M_L 300
boolean visited[M_L][M_L + 1] = { False };
ND queue[M_L * M_L + 1];
int front = 0, rear = 1;
int dir[2][8] = {
	{2,2,1,1,-1,-1,-2,-2} ,
	{1,-1,2,-2,2,-2,1,-1}
};

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int l;
		scanf("%d", &l);
		int a, b;
		scanf("%d %d", &a, &b);

		for (int i = 0; i < M_L; ++i) {
			for (int j = 0; j < M_L; ++j) {
				visited[i][j] = False;
			}
		}

		visited[a][b] = True;
		front = 0, rear = 1;
		queue[0] = (ND) { a, b, 0 };

		int end1, end2;
		scanf("%d %d", &end1, &end2);

		while (front != rear) {
			ND node = queue[front++];
			if (node.x == end1 && node.y == end2) {
				printf("%d\n", node.moved);
				break;
			}

			for (int i = 0; i < 8; ++i) {
				ND newNode = (ND) { node.x + dir[0][i], node.y + dir[1][i], node.moved + 1 };
				if (0 <= newNode.x && newNode.x < l && 0 <= newNode.y && newNode.y < l && !visited[newNode.x][newNode.y]) {
					visited[newNode.x][newNode.y] = True;
					queue[rear++] = newNode;
				}
			}
		}
	}

	return 0;
}