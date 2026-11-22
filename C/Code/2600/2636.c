#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 100
#define MAX_DIR 4

typedef struct Position {
	int x, y;
} Position;

const Position dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isCheeze[MAX_IDX + 2][MAX_IDX + 2];
bool visit[MAX_IDX + 2][MAX_IDX + 2];
int n, m;
int cnt_cheeze;

Position q[(MAX_IDX + 2) * (MAX_IDX + 2) + 1];
int front, rear;

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int x;
			scanf("%d", &x);
			isCheeze[i][j] = (x == 1);
			cnt_cheeze += (x == 1);

			visit[i][j] = false;
		}
	}
	return;
}

void dfs(int x, int y) {
	for (int i = 0; i < MAX_DIR; ++i) {
		Position newPos = (Position){x + dir[i].x, y + dir[i].y};
		if (0 <= newPos.x && newPos.x <= n + 1 && 0 <= newPos.y && newPos.y <= m + 1) {
			if (visit[newPos.x][newPos.y] == false) {
				visit[newPos.x][newPos.y] = true;

				if (isCheeze[newPos.x][newPos.y] == true) { // 치즈인 경우
					q[rear++] = newPos;
				} else {
					dfs(newPos.x, newPos.y); // 공기인 경우
				}
			}
		}
	}
	return;
}

void init() {
	front = rear = 0;

	// dfs를 통해 모든 air를 탐색하면서, 처음 cheeze를 만날 때까지 진행해야 함
	// 결과적으로 q에 "바깥 공기와 맞닿아있는" 치즈를 넣는 것이 목표
	// 현재는 최외각만 바깥인데, (0,0)은 항상 비어있으며, 이 지점부터 시작하면 모두 커버 가능함
	dfs(0, 0);
	return;
}

void melt() {
	int limit = rear; // 이번 시간의 상한선
	while (front < limit) {
		Position cur = q[front++];
		isCheeze[cur.x][cur.y] = false, cnt_cheeze -= 1;
		dfs(cur.x, cur.y); // 여기부터 다시 dfs 시작할 수 있음
	}
	return;
}

int main() {
	read_input();
	init();

	int time = 0, ans = cnt_cheeze;
	while (true) { // 모두 녹아 없어질 때까지 반복
		time += 1;
		melt(); // 녹는 작업을 1회 진행

		if (cnt_cheeze == 0) { // 치즈가 모두 녹았다면 종료
			break;
		} else {
			ans = cnt_cheeze;
		}
	}
	printf("%d\n%d", time, ans);
	return 0;
}