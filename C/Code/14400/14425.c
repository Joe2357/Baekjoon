#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 500
#define MAX_IDX 10000
#define MOD 200003
const int ALPHABET = 26;

typedef struct HashNode {
	char str[MAX_LEN + 1];
	struct HashNode* next;
} HN;

int n, m;
char input[MAX_LEN + 1];
HN* hashmap[MOD + 1];

int getHash(char* s) {
	int ret = 0;
	for (int i = 0; s[i] != '\0'; ++i) {
		ret = (ret * ALPHABET + s[i] - 'a') % MOD;
	}
	return ret;
}

void insertHashMap(char* s) {
	int h = getHash(s);
	HN* newNode = (HN*)malloc(sizeof(HN));
	strcpy(newNode->str, input);
	newNode->next = hashmap[h], hashmap[h] = newNode;
	return;
}

bool isInHashMap(char* s) {
	int h = getHash(s);
	for (HN* cur = hashmap[h]; cur != NULL; cur = cur->next) {
		if (strcmp(s, cur->str) == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%s", input);
		insertHashMap(input);
	}

	int ret = 0;
	while (m--) {
		scanf("%s", input);
		ret += isInHashMap(input);
	}
	printf("%d", ret);
	return 0;
}