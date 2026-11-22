#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_SIZE (1000 + 10)

typedef struct QueueNode {
	int idx;
	int move_cnt;
} QueueNode;

int n;
QueueNode round_queue[MAX_SIZE]; // 여유공간 설정
int front, rear;

bool isQueueEmpty() {
	return (front == rear);
}
int size() {
	return (rear - front + MAX_SIZE) % MAX_SIZE;
}
void push_back(QueueNode node) {
	round_queue[rear] = node;
	rear = (rear + 1) % MAX_SIZE;
}
void push_front(QueueNode node) {
	front = (front - 1 + MAX_SIZE) % MAX_SIZE;
	round_queue[front] = node;
}
QueueNode pop_front() {
	QueueNode res = round_queue[front];
	front = (front + 1) % MAX_SIZE;
	return res;
}
QueueNode pop_back() {
	rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
	return round_queue[rear];
}

void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		push_back((QueueNode){i, x});
	}
	return;
}

int main() {
	init();

	while (isQueueEmpty() == false) {
		QueueNode cur = pop_front();
		printf("%d ", cur.idx);

		if (isQueueEmpty() == true) {
			break;
		}

		if (cur.move_cnt > 0) { // step이 양수 = 오른쪽 이동
			int s = cur.move_cnt;
			for (int i = 1; i < s; ++i) { // 앞에서 이미 pop을 한번 함
				push_back(pop_front());
			}

		} else {
			int s = 0 - cur.move_cnt;
			for (int i = 0; i < s; ++i) {
				push_front(pop_back());
			}
		}
	}
	return 0;
}