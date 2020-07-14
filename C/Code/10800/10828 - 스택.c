#include <stdio.h>
#include <string.h>

int main(n) {
	int arr[10000], top = -1;
	for (scanf("%d", &n); n; n--) {
		char str[10];
		scanf("%s", str);

		if (!strcmp(str, "push")) { // push to stack
			int temp;
			scanf("%d", &temp);
			arr[++top] = temp;
		}

		else if (!strcmp(str, "pop"))
			if (top == -1)
				// stack is empty
				printf("-1\n");
			else
				// stack is not empty
				printf("%d\n", arr[top--]);

		else if (!strcmp(str, "size"))
			printf("%d\n", top + 1);

		else if (!strcmp(str, "empty"))
			if (top == -1)
				printf("1\n");
			else
				printf("0\n");

		else if (!strcmp(str, "top"))
			if (top == -1)
				printf("-1\n");
			else
				printf("%d\n", arr[top]);
	}
	return 0;
}