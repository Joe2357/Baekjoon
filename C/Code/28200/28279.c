#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define INSERT_FRONT 1
#define INSERT_BACK 2
#define POP_FRONT 3
#define POP_BACK 4
#define PRINT_LEN 5
#define PRINT_ISEMPTY 6
#define PRINT_FRONT 7
#define PRINT_BACK 8
const int NONE = -1;

typedef struct LinkedListNode {
	int x;
	struct LinkedListNode* left;
	struct LinkedListNode* right;
} LLN;

LLN *head, *tail;
int len;

LLN* createNewNode(int x, LLN* left, LLN* right) {
	LLN* newNode = (LLN*)malloc(sizeof(LLN));
	newNode->x = x;
	newNode->left = left, newNode->right = right;
	return newNode;
}

bool isEmpty() {
	return len == 0;
}

void insert_front(int x) {
	if (isEmpty() == true) {
		head = createNewNode(x, NULL, NULL);
		tail = head;
	} else {
		head->left = createNewNode(x, NULL, head);
		head = head->left;
	}
	len += 1;
	return;
}

void insert_back(int x) {
	if (isEmpty() == true) {
		head = createNewNode(x, NULL, NULL);
		tail = head;
	} else {
		tail->right = createNewNode(x, tail, NULL);
		tail = tail->right;
	}
	len += 1;
	return;
}

void pop_front() {
	if (isEmpty() == true) {
		printf("%d\n", NONE);
	} else {
		printf("%d\n", head->x);
		head = head->right;
		len -= 1;

		if (isEmpty() == true) {
			head = tail = NULL;
		}
	}
	return;
}

void pop_back() {
	if (isEmpty() == true) {
		printf("%d\n", NONE);
	} else {
		printf("%d\n", tail->x);
		tail = tail->left;
		len -= 1;

		if (isEmpty() == true) {
			head = tail = NULL;
		}
	}
	return;
}

void print_front() {
	if (len == 0) {
		printf("%d\n", NONE);
	} else {
		printf("%d\n", head->x);
	}
	return;
}

void print_back() {
	if (len == 0) {
		printf("%d\n", NONE);
	} else {
		printf("%d\n", tail->x);
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int command;
		scanf("%d", &command);
		switch (command) {
			case INSERT_FRONT: {
				int x;
				scanf("%d", &x);
				insert_front(x);
				break;
			}
			case INSERT_BACK: {
				int x;
				scanf("%d", &x);
				insert_back(x);
				break;
			}
			case POP_FRONT: {
				pop_front();
				break;
			}
			case POP_BACK: {
				pop_back();
				break;
			}
			case PRINT_LEN: {
				printf("%d\n", len);
				break;
			}
			case PRINT_ISEMPTY: {
				printf("%d\n", (len == 0));
				break;
			}
			case PRINT_FRONT: {
				print_front();
				break;
			}
			case PRINT_BACK: {
				print_back();
				break;
			}
		}
	}
	return 0;
}