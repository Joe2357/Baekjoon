#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100000

int arr[MAX_IDX], front, rear;
int n;
char command[MAX_IDX + 1];
char input[MAX_IDX * 4 + 3];
bool mode, isError;

void init() {
	front = rear = 0;
	mode = false;
	isError = false;
	return;
}

void read_input() {
	scanf("%s", command);
	scanf("%d", &n);
	scanf("%s", input);
	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		init();
		read_input();

		/* input array preprocessing */
		for (int i = 0, temp = 0; input[i]; i++) {
			if (input[i] >= '0' && input[i] <= '9') {
				temp = temp * 10 + input[i] - '0';
			} else {
				if (temp > 0) {
					arr[rear++] = temp;
				}
				temp = 0;
			}
		}

		/* command processing */
		for (int i = 0; command[i]; i++) {
			if (isError)
				break;

			switch (command[i]) {
			case 'R':
				mode = !mode;
				break;
			case 'D':
				if (front == rear) {
					isError = true;
					break;
				}
				if (mode) {
					rear--;
				} else {
					front++;
				}
				break;
			}
		}

		/* result print */
		if (isError) {
			printf("error\n");
		} else if (front == rear) {
			printf("[]\n");
		} else if (mode) {
			printf("[");
			for (int i = rear - 1; i > front; i--)
				printf("%d,", arr[i]);
			printf("%d]\n", arr[front]);
		} else {
			printf("[");
			for (int i = front; i < rear - 1; i++) {
				printf("%d,", arr[i]);
			}
			printf("%d]\n", arr[rear - 1]);
		}
	}
	return 0;
}