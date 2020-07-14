#include <stdio.h>

int main(n, k) {
	int arr[101][101] = { 0 }, visit[101] = { 0 }, queue[10000] = { 1 }, front = 0, rear = 1, r = 0;
	for (scanf("%d %d", &n, &k); k; k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1, arr[b][a] = 1;   // store edge
	}
	while (front != rear) {             // BFS Algorithm
		int temp = queue[front++];      // pop 1 vertax
		if (visit[temp])                // if already visited
			continue;
		visit[temp] = 1, r++;            // visit check, that computer is infected by virus
		for (int i = 1; i < 101; i++)
			if (arr[temp][i])           // if has edge ( if computer connect each )
				queue[rear++] = i;      // push another vertax in queue
	}
	printf("%d", r - 1);
	return 0;
}