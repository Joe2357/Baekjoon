#include <stdio.h>
#include <string.h>

int main() {
	int n, arr[10000] = {0}, front = -1, rear = -1;
	scanf("%d", &n);
	char str[10];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		if (!strcmp(str, "push")) {
			int temp;
			scanf("%d", &temp);
			arr[++rear] = temp;
		} else if (!strcmp(str, "pop"))
			if (front >= rear)
				printf("-1\n");
			else
				printf("%d\n", arr[++front]);
		else if (!strcmp(str, "size"))
			printf("%d\n", rear - front);
		else if (!strcmp(str, "empty"))
			if (front >= rear)
				printf("1\n");
			else
				printf("0\n");
		else if (!strcmp(str, "front"))
			if (front >= rear)
				printf("-1\n");
			else
				printf("%d\n", arr[front + 1]);
		else if (!strcmp(str, "back"))
			if (front >= rear)
				printf("-1\n");
			else
				printf("%d\n", arr[rear]);
	}
}