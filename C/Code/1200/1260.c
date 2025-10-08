#include <stdio.h>

int arr[1001][1001], DFS_visited[1001]; // default 0

void DFS(int v, int n) {	// fuction DFS recursive
	if (!DFS_visited[v]) {	// if not visited
		DFS_visited[v] = 1; // check visited
		printf("%d ", v);
		for (int i = 1; i <= n; i++) // search new node
			if (arr[v][i])			 // if there is a line
				DFS(i, n);			 // set new node
	}
	return;
}

int main(n, m, v) {
	int BFS_visited[1001] = {0}, queue[20000], front = 0, rear = 1;
	for (scanf("%d %d %d", &n, &m, &v); m; m--) { // input grid
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1, arr[b][a] = 1;
	}
	DFS(v, n); // DFS search
	printf("\n");
	queue[0] = v;
	while (front != rear) {		   // while queue is not empty
		int temp = queue[front++]; // current node
		if (!BFS_visited[temp]) {  // if not visited
			BFS_visited[temp] = 1; // check visited
			printf("%d ", temp);
			for (int i = 1; i <= n; i++) // search new node
				if (arr[i][temp])		 // if there is line
					queue[rear++] = i;	 // qush new node to queue
		}
	}
	return 0;
}