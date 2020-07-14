#include <stdio.h>

int main(t) {
	// test case
	for (scanf("%d", &t); t; t--) {
		int arr[100000];

		// command length <= 100,000
		char command[100001];
		scanf("%s", command);

		int n, front = 0, rear = 0, mode = 0, boolean = 0;

		// number array length : n
		scanf("%d", &n);
		char tempArr[400003];
		scanf("%s", tempArr);
		// array string -> int mapping
		for (int i = 0, temp = 0; tempArr[i]; i++)
			if (tempArr[i] >= '0' && tempArr[i] <= '9')
				temp = temp * 10 + tempArr[i] - '0';
			else {
				if (temp)
					arr[rear++] = temp;
				temp = 0;
			}

		// command queue
		for (int i = 0; command[i]; i++) {
			switch (command[i]) {
				case 'R':
					// mode 0 : ->
					// mode 1 : <-
					mode = 1 - mode;
					break;
				case 'D':
					// pop function
					// if queue is empty
					if (front == rear) {
						boolean = 1;
						printf("error\n");
						break;
					}
					// else if ->
					else if (mode)
						rear--;
					// else if <-
					else
						front++;
					break;
			}
			// if an error occurred
			if (boolean)
				break;
		}
		// if an error occurred
		if (boolean)
			continue;
		// else queue is empty
		else if (front == rear) {
			printf("[]\n");
			continue;
		}
		// else queue is not empty
		switch (mode) {
			case 0:
				// -> pos
				printf("[");
				for (int i = front; i < rear - 1; i++)
					printf("%d,", arr[i]);
				printf("%d]\n", arr[rear - 1]);
				break;
			case 1:
				// <- pos
				printf("[");
				for (int i = rear - 1; i > front; i--)
					printf("%d,", arr[i]);
				printf("%d]\n", arr[front]);
				break;
		}
	}
	return 0;
}