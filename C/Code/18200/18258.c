#include <stdio.h>
#include <string.h>

int main(t) {
	int arr[2000000], front = 0, rear = 0, temp;
	char command[10];
	for (scanf("%d", &t); t; t--) {
		scanf("%s", command);
		if (!strcmp(command, "push")) {
			scanf("%d", &temp);
			arr[rear++] = temp;
		} else if (!strcmp(command, "pop"))
			if (rear - front)
				printf("%d\n", arr[front++]);
			else
				printf("-1\n");
		else if (!strcmp(command, "size"))
			printf("%d\n", rear - front);
		else if (!strcmp(command, "empty"))
			printf("%d\n", !(rear - front));
		else if (!strcmp(command, "front"))
			if (rear - front)
				printf("%d\n", arr[front]);
			else
				printf("-1\n");
		else if (!strcmp(command, "back"))
			if (rear - front)
				printf("%d\n", arr[rear - 1]);
			else
				printf("-1\n");
	}
	return 0;
}