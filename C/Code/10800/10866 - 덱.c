#include <stdio.h>
#include <string.h>

int main(t) {
	// O O O O O D O O O O O
	int front = 10000, rear = 10000, arr[20001];
	for (int i = 0; i < 20001; i++) // first init
		arr[i] = -1;
	for (scanf("%d", &t); t; t--) {
		char str[20];
		scanf("%s", str);
		if (!strcmp(str, "push_front")) {
			int temp;
			scanf("%d", &temp);
			arr[front--] = temp;
		}
		else if (!strcmp(str, "push_back")) {
			int temp;
			scanf("%d", &temp);
			arr[++rear] = temp;
		}
		else if (!strcmp(str, "pop_front"))
			if (front == rear)
				printf("-1\n");
			else {
				printf("%d\n", arr[++front]);
				arr[front] = -1;
			}
		else if (!strcmp(str, "pop_back"))
			if (front == rear)
				printf("-1\n");
			else {
				printf("%d\n", arr[rear--]);
				arr[rear + 1] = -1;
			}
		else if (!strcmp(str, "size"))
			printf("%d\n", rear - front);
		else if (!strcmp(str, "empty"))
			if (front == rear)
				printf("1\n");
			else
				printf("0\n");
		else if (!strcmp(str, "front")) {
			if (front == rear)
				printf("-1\n");
			else {
				int temp = front;
				while (arr[temp] == -1)
					temp++;
				if (temp > rear)
					printf("-1\n");
				else
					printf("%d\n", arr[temp]);
			}
		}
		else if (!strcmp(str, "back")) {
			if (front == rear)
				printf("-1\n");
			else {
				int temp = rear;
				while (arr[temp] == -1)
					temp--;
				if (temp < front)
					printf("-1\n");
				else
					printf("%d\n", arr[temp]);
			}
		}
	}
}