#include <stdio.h>

typedef struct Node {
	int value;
	int count;
} ND;

typedef char boolean;
#define True 1
#define False 0

#define MAX_INDEX (int)1e4
boolean isNotPrime[MAX_INDEX + 1];

void init() {
	isNotPrime[0] = True, isNotPrime[1] = True;
	for (int i = 2; i <= MAX_INDEX; ++i)
		if (!isNotPrime[i])
			for (int j = i * 2; j <= MAX_INDEX; j += i)
				isNotPrime[j] = True;
	return;
}

int main() {
	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		boolean visited[MAX_INDEX + 1] = { False };
		visited[a] = True;
		ND queue[MAX_INDEX] = { {a, 0} };
		int front = 0, rear = 1;
		boolean isAnswerExists = False;

		while (front != rear) {
			ND node = queue[front++];
			if (node.value == b) {
				printf("%d\n", node.count);
				isAnswerExists = True;
				break;
			}

			for (int i = 0; i < 10; ++i) {
				int temp;
				/* 1000 */
				if (i != 0) {
					temp = (node.value % 1000) + (i * 1000);
					if (!isNotPrime[temp] && !visited[temp]) {
						visited[temp] = True;
						queue[rear++] = (ND) { temp, node.count + 1 };
					}
				}

				/* 100 */
				temp = (node.value / 1000 * 1000) + (i * 100) + (node.value % 100);
				if (!isNotPrime[temp] && !visited[temp]) {
					visited[temp] = True;
					queue[rear++] = (ND) { temp, node.count + 1 };
				}

				/* 10 */
				temp = (node.value / 100 * 100) + (i * 10) + (node.value % 10);
				if (!isNotPrime[temp] && !visited[temp]) {
					visited[temp] = True;
					queue[rear++] = (ND) { temp, node.count + 1 };
				}

				/* 1 */
				temp = (node.value / 10 * 10) + (i);
				if (!isNotPrime[temp] && !visited[temp]) {
					visited[temp] = True;
					queue[rear++] = (ND) { temp, node.count + 1 };
				}
			}
		}

		if (!isAnswerExists)
			printf("Impossible\n");
	}
}