#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int imoticon_cnt;
	int clipboard_cnt;
	int time;
} ND;

const int INF = 987654321;
#define MAX_IDX 1000

ND queue[(MAX_IDX * 2 + 1) * (MAX_IDX + 1)];
int front = 0, rear = 0;

char visit[MAX_IDX * 2 + 1][MAX_IDX + 1];
int s;

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	scanf("%d", &s);

	visit[1][0] = true;
	queue[rear++] = (ND){1, 0, 0};

	int ret = INF;
	while (front < rear) {
		ND cur = queue[front++];
		if (cur.imoticon_cnt == s) {
			ret = cur.time;
			break;
		} else if (cur.imoticon_cnt >= 2 * s) {
			ret = min(ret, cur.time + (cur.imoticon_cnt - s));
			continue;
		} else {
			// 1. copy all
			if (visit[cur.imoticon_cnt][cur.imoticon_cnt] == false) {
				visit[cur.imoticon_cnt][cur.imoticon_cnt] = true;
				queue[rear++] = (ND){cur.imoticon_cnt, cur.imoticon_cnt, cur.time + 1};
			}

			// 2. paste
			if (cur.clipboard_cnt > 0 && cur.imoticon_cnt + cur.clipboard_cnt <= 2 * s) {
				if (visit[cur.imoticon_cnt + cur.clipboard_cnt][cur.clipboard_cnt] == false) {
					visit[cur.imoticon_cnt + cur.clipboard_cnt][cur.clipboard_cnt] = true;
					queue[rear++] = (ND){cur.imoticon_cnt + cur.clipboard_cnt, cur.clipboard_cnt, cur.time + 1};
				}
			}

			// 3. delete one
			if (cur.imoticon_cnt > 0) {
				if (visit[cur.imoticon_cnt - 1][cur.clipboard_cnt] == false) {
					visit[cur.imoticon_cnt - 1][cur.clipboard_cnt] = true;
					queue[rear++] = (ND){cur.imoticon_cnt - 1, cur.clipboard_cnt, cur.time + 1};
				}
			}
		}
	}
	printf("%d", ret);
	return 0;
}