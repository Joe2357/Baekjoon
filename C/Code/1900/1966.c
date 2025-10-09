#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Document {
	int number;
	int priority;
	struct Document* next;
} Document;

#define MAX_DOCUMENT 100

Document *head, *tale;

#define max(a, b) ((a) > (b) ? (a) : (b))

void init() {
	Document* next;
	for (Document* current = head; current != NULL; current = next) {
		next = current->next;
		free(current);
	}
	head = tale = NULL;
	return;
}

bool isListEmpty(Document* head) {
	return (head == NULL);
}

void ListPush(int number, int priority) {
	Document* new_document = (Document*)malloc(sizeof(Document));
	new_document->number = number;
	new_document->priority = priority;
	new_document->next = NULL;

	if (isListEmpty(head) == true) {
		head = tale = new_document;
	} else {
		tale->next = new_document;
		tale = new_document;
	}
	return;
}

Document* ListPop() {
	Document* pop_document = head;
	head = head->next;
	tale = (head == NULL ? NULL : tale);
	return pop_document;
}

int get_max_priority() {
	int max_priority = -1;
	for (Document* current = head; current != NULL; current = current->next) {
		max_priority = max(max_priority, current->priority);
	}
	return max_priority;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();

		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			int priority;
			scanf("%d", &priority);
			ListPush(i, priority);
		}

		for (int popped_cnt = 0; isListEmpty(head) == false;) {
			Document* current = ListPop();
			if (current->priority >= get_max_priority()) {
				popped_cnt += 1;

				if (current->number == m) {
					printf("%d\n", popped_cnt);
					free(current);
					break;
				} else {
					free(current);
				}
			} else {
				ListPush(current->number, current->priority);
				free(current);
			}
		}
	}
	return 0;
}