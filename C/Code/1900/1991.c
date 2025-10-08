#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char value;
	struct Node* left;
	struct Node* right;
} ND;

ND arr[26];
int n;

void init() {
	for (int i = 0; i < 26; i++) {
		arr[i].value = 'A' + i;
		arr[i].left = NULL;
		arr[i].right = NULL;
	}
	return;
}

void frontSearch(ND* node) {
	if (node) {
		printf("%c", node->value);
		frontSearch(node->left);
		frontSearch(node->right);
	}
	return;
}
void middleSearch(ND* node) {
	if (node) {
		middleSearch(node->left);
		printf("%c", node->value);
		middleSearch(node->right);
	}
	return;
}
void endSearch(ND* node) {
	if (node) {
		endSearch(node->left);
		endSearch(node->right);
		printf("%c", node->value);
	}
	return;
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char t1, t2, t3;
		scanf(" %c %c %c", &t1, &t2, &t3);
		if (t2 != '.')
			arr[t1 - 'A'].left = &arr[t2 - 'A'];
		if (t3 != '.')
			arr[t1 - 'A'].right = &arr[t3 - 'A'];
	}
	frontSearch(&arr[0]);
	printf("\n");
	middleSearch(&arr[0]);
	printf("\n");
	endSearch(&arr[0]);
	return 0;
}