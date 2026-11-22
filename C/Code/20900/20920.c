#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS (int)(1e5)
#define MAX_HASH 10003
#define MAX_LEN 10

typedef struct ListNode {
	char word[MAX_LEN + 1];
	int len;
	int cnt;
	struct ListNode* next;
} ListNode;

ListNode* hashmap[MAX_HASH];
int n, m;

ListNode* words[MAX_WORDS];
int l;

int get_hash(char* str) {
	int ret = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		ret = ret * 33 + str[i];
		ret %= MAX_HASH;
	}
	return ret;
}

void insert(char* str) {
	int hash = get_hash(str);
	for (ListNode* cur = hashmap[hash]; cur != NULL; cur = cur->next) {
		if (strcmp(str, cur->word) == 0) {
			cur->cnt += 1;
			return;
		}
	}

	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->word, str);
	newNode->len = strlen(str);
	newNode->cnt = 1;
	newNode->next = hashmap[hash];
	hashmap[hash] = newNode;
	return;
}

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		char str[MAX_LEN + 1];
		scanf("%s", str);

		if (strlen(str) >= m) {
			insert(str);
		}
	}
	return;
}

int words_asc(const void* a, const void* b) {
	ListNode *x = *(ListNode**)a, *y = *(ListNode**)b;

	if (x->cnt > y->cnt) {
		return -1;
	} else if (x->cnt < y->cnt) {
		return 1;
	}

	if (x->len > y->len) {
		return -1;
	} else if (x->len < y->len) {
		return 1;
	}

	if (strcmp(x->word, y->word) > 0) {
		return 1;
	} else {
		return -1;
	}
}

void init() {
	l = 0;
	for (int i = 0; i < MAX_HASH; ++i) {
		for (ListNode* cur = hashmap[i]; cur != NULL; cur = cur->next) {
			words[l++] = cur;
		}
	}
	qsort(words, l, sizeof(ListNode*), words_asc);
	return;
}

void print_words_array() {
	for (int i = 0; i < l; ++i) {
		printf("%s\n", words[i]->word);
	}
	return;
}

int main() {
	read_input();
	init();
	print_words_array();
	return 0;
}