#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH 1003
#define MAX_LEN 20
const char entering_message[MAX_LEN + 1] = "ENTER";

typedef struct ListNode {
	char name[MAX_LEN + 1];
	struct ListNode* next;
} ListNode;
typedef struct HashMap {
	ListNode* map[MAX_HASH];
} HashMap;

HashMap* hashmap;
int n;

void clear_map() {
	/*
	for (int i = 0; i < MAX_HASH; ++i) {
		hashmap[i] = NULL;
	}
	*/
	if (hashmap != NULL) {
		free(hashmap);
	}
	hashmap = (HashMap*)calloc(1, sizeof(HashMap));
	return;
}

int getHash(char* str) {
	int ret = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		ret = (ret * 33) + str[i];
		ret %= MAX_HASH;
	}
	return ret;
}

bool exists(char* str) {
	int hash = getHash(str);

	for (ListNode* cur = hashmap->map[hash]; cur != NULL; cur = cur->next) {
		if (strcmp(cur->name, str) == 0) {
			return true;
		}
	}
	return false;
}

void insert(char* str) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->name, str);
	int hash = getHash(str);
	newNode->next = hashmap->map[hash];
	hashmap->map[hash] = newNode;
	return;
}

int main() {
	hashmap = NULL;
	scanf("%d", &n);
	// clear_map(); // 입력으로 주어지는 문자열이 무조건 ENTER이므로, 사전에 초기화할 필요까지는 없음

	int ans = 0;
	while (n--) {
		char input[MAX_LEN + 1];
		scanf("%s", input);

		if (strcmp(input, entering_message) == 0) { // 누군가의 입장 메세지라면
			clear_map();
		} else {
			if (exists(input) == false) {
				ans += 1;
				insert(input);
			}
		}
	}
	printf("%d", ans);
	return 0;
}