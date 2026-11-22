#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 1000000

typedef struct Node {
	int v;	  // 실제 숫자 값
	int used; // 사용된 숫자 비트마스크
} Node;

Node arr[MAX_SIZE];
int front, rear;

void init() {
	for (int i = 1; i < 10; ++i) {
		arr[rear++] = (Node){i, (1 << i)};
	}

	while (front < rear) {
		Node cur = arr[front++];

		for (int i = 1; i < 10; ++i) {
			if ((cur.used & (1 << i)) == 0) {
				if (cur.v < (int)(1e8)) {
					arr[rear++] = (Node){cur.v * 10 + i, cur.used | (1 << i)};
				}
			}
		}
	}
	return;
}

// upper bound 구현
int find(int x) {
	int low = 0, high = rear - 1;
	int res = -1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid].v > x) {
			res = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return (res == -1) ? MAX_SIZE : res;
}

int main() {
	init();

	int n;
	while (scanf("%d", &n) != EOF) {
		int idx = find(n);

		if (idx >= MAX_SIZE) {
			printf("0\n");
		} else {
			printf("%d\n", arr[idx].v);
		}
	}
	return 0;
}