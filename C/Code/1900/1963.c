#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int INF = 987654321;
#define MAX_IDX 10000

bool isNotPrime[MAX_IDX] = {true, true};

void prime_init() {
	for (int i = 2; i < MAX_IDX; ++i) {
		if (isNotPrime[i] == false) {
			for (int j = i * 2; j < MAX_IDX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}

typedef struct QueueNode {
	int num;
	int cnt;
} QN;

int t;
int a, b;
QN q[MAX_IDX + 1];
bool visit[MAX_IDX + 1];
int front, rear;
int retval;

int main() {
	prime_init();
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &a, &b);

		for (int i = 0; i < MAX_IDX; ++i) {
			visit[i] = false;
		}
		retval = INF;
		front = rear = 0;
		visit[a] = true;
		q[rear++] = (QN){a, 0};

		while (front < rear) {
			QN node = q[front++];
			if (node.num == b) {
				retval = node.cnt;
				break;
			}

			for (int digit = 1; digit < MAX_IDX; digit *= 10) {
				int std = node.num - (((node.num % (digit * 10)) / digit) * digit);

				for (int j = 0; j < 10; ++j) {
					int temp = std + (j * digit);

					if (temp < 1000) {
						continue;
					} else if (isNotPrime[temp] == false && visit[temp] == false) {
						visit[temp] = true;
						q[rear++] = (QN){temp, node.cnt + 1};
					}
				}
			}
		}

		if (retval < INF) {
			printf("%d\n", retval);
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}