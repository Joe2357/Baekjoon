#include <stdio.h>
#include <string.h>
#define MAX_INDEX 10000
#define True 1
#define False 0

typedef struct MyStruct {
	int value;
	char str[21];
} MS;

typedef char boolean;

int op_d(int x) {
	return (2 * x) % 10000;
}

int op_s(int x) {
	return --x + 10000 * (x < 0);
}

int op_l(int x) {
	int a = x / 1000;
	x %= 1000;
	x *= 10;
	return x + a;
}

int op_r(int x) {
	int a = x % 10;
	x /= 10;
	return a * 1000 + x;
}

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int a, b;
		scanf("%d %d", &a, &b);

		// BFS search
		MS Queue[MAX_INDEX + 1] = { 0 };
		boolean visited[MAX_INDEX + 1] = { 0 };
		int front = 0, rear = 0;

		// start position init
		visited[a] = True;
		Queue[rear++].value = a;

		// search start
		while (front != rear) {
			MS temp = Queue[front++];
			if (temp.value == b) { // end point
				printf("%s\n", temp.str);
				break;
			}

			// push another value

			// section D
			int ret_d = op_d(temp.value);
			if (!visited[ret_d]) {
				visited[ret_d] = True;
				Queue[rear].value = ret_d;
				strcpy(Queue[rear].str, temp.str);
				strcat(Queue[rear++].str, "D");
			}

			// section S
			int ret_s = op_s(temp.value);
			if (!visited[ret_s]) {
				visited[ret_s] = True;
				Queue[rear].value = ret_s;
				strcpy(Queue[rear].str, temp.str);
				strcat(Queue[rear++].str, "S");
			}

			// section L
			int ret_l = op_l(temp.value);
			if (!visited[ret_l]) {
				visited[ret_l] = True;
				Queue[rear].value = ret_l;
				strcpy(Queue[rear].str, temp.str);
				strcat(Queue[rear++].str, "L");
			}

			// section R
			int ret_r = op_r(temp.value);
			if (!visited[ret_r]) {
				visited[ret_r] = True;
				Queue[rear].value = ret_r;
				strcpy(Queue[rear].str, temp.str);
				strcat(Queue[rear++].str, "R");
			}
		}
	}
	return 0;
}