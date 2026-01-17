#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAP_SIZE 10007
const int HASH_BASE = 31;
#define MAX_LEN 50

typedef struct MapNode {
	char key[MAX_LEN];
	int value;
	struct MapNode* next;
} MapNode;

char input[MAX_LEN];
MapNode* hashMap[MAP_SIZE];

#define max(a, b) ((a) > (b) ? (a) : (b))

int getHash(const char* key) {
	int hash = 0;
	for (int i = 0; key[i] != '\0'; ++i) {
		hash = (hash * HASH_BASE + key[i]) % MAP_SIZE;
	}
	return hash;
}

MapNode* find(const char* key) {
	int hash = getHash(key);

	for (MapNode* node = hashMap[hash]; node != NULL; node = node->next) {
		if (strcmp(node->key, key) == 0) {
			return node;
		}
	}
	return NULL;
}
MapNode* insertNewMode(const char* key) {
	int hash = getHash(key);

	MapNode* newNode = (MapNode*)malloc(sizeof(MapNode));
	strcpy(newNode->key, key);
	newNode->value = 1;
	newNode->next = hashMap[hash];
	hashMap[hash] = newNode;

	return newNode;
}

int main() {
	int n;
	scanf("%d", &n);

	int current_max_appearance = 0;
	while (n--) {
		int s, t;
		scanf("%d %d", &s, &t);
		while (t--) {
			scanf("%s", input);
			MapNode* node = find(input);

			if (node == NULL) {
				node = insertNewMode(input);
			} else {
				node->value += 1;
			}
			current_max_appearance = max(current_max_appearance, node->value);
		}
	}

	char result[MAX_LEN];
	bool isAnswerFound = false, isDuplicateFound = false;
	for (int i = 0; i < MAP_SIZE; ++i) {
		for (MapNode* node = hashMap[i]; node != NULL; node = node->next) {
			if (node->value == current_max_appearance) {
				if (isAnswerFound == true) {
					isDuplicateFound = true;
					break;
				} else {
					isAnswerFound = true;
					strcpy(result, node->key);
				}
			}
		}
	}

	if (isDuplicateFound == true) {
		printf("-1");
	} else {
		printf("%s", result);
	}
	return 0;
}