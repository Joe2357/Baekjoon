#include <stdio.h>

typedef struct Node {
	char c;
	int l;
} ND;

#define MAX_LEN 50

char str[MAX_LEN + 1];
ND stack[MAX_LEN];
int top = -1;

int main() {
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; ++i) {
		switch (str[i]) {
			case '(': {
				stack[++top] = (ND){'(', 0};
				break;
			}
			case ')': {
				int tmp = 0;
				while (stack[top].c != '(') {
					tmp += stack[top--].l;
				}
				top -= 1;

				int node_k = stack[top--].c - '0';
				stack[++top] = (ND){0, tmp * node_k};
				break;
			}
			default: {
				stack[++top] = (ND){str[i], 1};
			}
		}
	}

	int ret = 0;
	for (int i = 0; i <= top; ++i) {
		ret += stack[i].l;
	}
	printf("%d", ret);
	return 0;
}