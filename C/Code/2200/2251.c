#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct State {
	int a, b, c;
} State;

#define MAX_IDX 200

bool feasible[MAX_IDX + 1 + 1];
bool visit[MAX_IDX + 1][MAX_IDX + 1 + 1]; // cur.a + cur.b + cur.c == c임이 항상 보장됨
State queue[MAX_IDX * MAX_IDX + 1];
int front, rear;
int a, b, c;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

void init() {
	visit[0][0] = true;
	queue[rear++] = (State){0, 0, c};
	return;
}

void solve() {
	while (front < rear) {
		State cur = queue[front++];
		if (cur.a == 0) {
			feasible[cur.c] = true;
		}

		if (a > 0) {
			// a -> b
			if (cur.b < b) {
				State new = cur;

				int ab = cur.a + cur.b;
				new.b = min(ab, b);
				new.a = ab - new.b;
				if (visit[new.a][new.b] == false) {
					visit[new.a][new.b] = true;
					queue[rear++] = new;
				}
			}

			// a -> c
			if (cur.c < c) {
				State new = cur;

				int ac = cur.a + cur.c;
				new.c = min(ac, c);
				new.a = ac - new.c;
				if (visit[new.a][new.b] == false) {
					visit[new.a][new.b] = true;
					queue[rear++] = new;
				}
			}
		}

		if (b > 0) {
			// b -> a
			if (cur.a < a) {
				State new = cur;

				int ba = cur.b + cur.a;
				new.a = min(ba, a);
				new.b = ba - new.a;
				if (visit[new.a][new.b] == false) {
					visit[new.a][new.b] = true;
					queue[rear++] = new;
				}
			}

			// b -> c
			if (cur.c < c) {
				State new = cur;

				int bc = cur.b + cur.c;
				new.c = min(bc, c);
				new.b = bc - new.c;
				if (visit[new.a][new.b] == false) {
					visit[new.a][new.b] = true;
					queue[rear++] = new;
				}
			}
		}

		if (c > 0) {
			// c -> a
			if (cur.a < a) {
				State new = cur;

				int ca = cur.c + cur.a;
				new.a = min(ca, a);
				new.c = ca - new.a;
				if (visit[new.a][new.b] == false) {
					visit[new.a][new.b] = true;
					queue[rear++] = new;
				}
			}

			// c -> b
			if (cur.b < b) {
				State new = cur;

				int cb = cur.c + cur.b;
				new.b = min(cb, b);
				new.c = cb - new.b;
				if (visit[new.a][new.b] == false) {
					visit[new.a][new.b] = true;
					queue[rear++] = new;
				}
			}
		}
	}
	return;
}

void print_result() {
	for (int i = 0; i <= c; ++i) {
		if (feasible[i] == true) {
			printf("%d ", i);
		}
	}
	return;
}

int main() {
	scanf("%d %d %d", &a, &b, &c);
	init();
	solve();
	print_result();
	return 0;
}