#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char value;
	struct Node *pre;
	struct Node *next;
} ND;

#define M_I (int)6e5
char str[M_I + 1];
ND *head;
ND *cursor;

ND *createNewNode(char v) {
	ND *newNode = (ND *)malloc(sizeof(ND));
	newNode->value = v;
	newNode->pre = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertNode(ND *newNode) {
	if (head == NULL) {
		head = newNode;
	}
	else if (cursor == NULL) {
		newNode->next = head;
		head->pre = newNode;
		head = newNode;
	}
	else {
		newNode->next = cursor->next;
		cursor->next = newNode;
		newNode->pre = cursor;
		if (newNode->next != NULL)
			newNode->next->pre = newNode;
	}
	cursor = newNode;
	return;
}

void moveLeft() {
	if (cursor != NULL)
		cursor = cursor->pre;
	return;
}
void moveRight() {
	if (cursor == NULL)
		cursor = head;
	else if (cursor->next != NULL)
		cursor = cursor->next;
	return;
}
void deleteNode() {
	if (cursor != NULL) {
		ND *target = cursor;
		if (cursor->pre != NULL)
			cursor->pre->next = cursor->next;
		if (cursor->next != NULL)
			cursor->next->pre = cursor->pre;
		cursor = cursor->pre;
		if (target == head)
			head = target->next;
		free(target);
	}
	return;
}

void printNode() {
	ND *cur = head;
	int len = 0;
	while (cur) {
		str[len++] = cur->value;
		cur = cur->next;
	}
	str[len++] = '\0';
	printf("%s", str);
	return;
}

int main() {
	scanf("%s", str);
	for (int i = 0; str[i]; ++i)
		insertNode(createNewNode(str[i]));

	int n;
	scanf("%d", &n);
	while (n--) {
		char input[2];
		scanf("%s", input);
		switch (input[0]) {
			case 'P':
			{
				scanf("%s", input);
				insertNode(createNewNode(input[0]));
				break;
			}
			case 'L':
			{
				moveLeft();
				break;
			}
			case 'D':
			{
				moveRight();
				break;
			}
			case 'B':
			{
				deleteNode();
				break;
			}
		}
	}

	printNode();
	return 0;
}