#include <stdio.h>

typedef struct Node {
	int left, right;
} ND;

#define MAX_IDX 10000
int input[MAX_IDX];
int len;

#define MAX_VAL (int)(1e6)
#define NOTEXIST -1
ND tree[MAX_VAL + 1];

int makeTree(int s, int e) {
	if (s == e) {
		return NOTEXIST;
	} else if (s + 1 == e) {
		tree[input[s]] = (ND){NOTEXIST, NOTEXIST};
		return input[s];
	}

	// current value = input[s]
	int temp = s + 1;
	while (temp < len && input[temp] < input[s]) {
		++temp;
	}
	tree[input[s]] = (ND){makeTree(s + 1, temp), makeTree(temp, e)};

	return input[s];
}

void printPostOrder(int x) {
	if (x == NOTEXIST) {
		return;
	}

	printPostOrder(tree[x].left);
	printPostOrder(tree[x].right);
	printf("%d\n", x);
	return;
}

int main() {
	int temp;
	while (~scanf("%d", &temp)) {  // input until EOF
		input[len++] = temp;
	}

	int root = makeTree(0, len);

	printPostOrder(root);
	return 0;
}