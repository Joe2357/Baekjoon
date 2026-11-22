#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH 10007
#define MAX_LEN 20

typedef struct ListNode {
	char name[MAX_LEN + 1];
	struct ListNode* next;
} ListNode;

ListNode* hashmap[MAX_HASH];

int get_hash(char* str) {
	int ret = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		ret = ret * 33 + str[i];
		ret %= MAX_HASH;
	}
	return ret;
}

bool exists(char* str) {
	int hash = get_hash(str);
	for (ListNode* cur = hashmap[hash]; cur != NULL; cur = cur->next) {
		if (strcmp(str, cur->name) == 0) {
			return true;
		}
	}
	return false;
}
void insert(char* str) {
	int hash = get_hash(str);
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->name, str);
	newNode->next = hashmap[hash];
	hashmap[hash] = newNode;
	return;
}

int main() {
	insert("ChongChong");

	int n;
	scanf("%d", &n);

	int ans = 1;
	while (n--) {
		char a[MAX_LEN + 1], b[MAX_LEN + 1];
		scanf("%s %s", a, b);

		bool exists_a = exists(a), exists_b = exists(b);

		if (exists_a == true && exists_b == false) {
			ans += 1;
			insert(b);
		} else if (exists_a == false && exists_b == true) {
			ans += 1;
			insert(a);
		}
	}
	printf("%d", ans);
	return 0;
}