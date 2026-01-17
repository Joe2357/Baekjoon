#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(2e5)
#define MOD (int)(1e6 + 3)

typedef struct LinkedListNode {
	int data;
	struct LinkedListNode* next;
} LinkedListNode;

LinkedListNode* hashmap[MOD];
int n, m;

int getHash(int key) {
	return key % MOD;
}

LinkedListNode* insertNewNode(int data) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode->data = data;

	int hashIdx = getHash(data);
	newNode->next = hashmap[hashIdx];
	hashmap[hashIdx] = newNode;
	return newNode;
}

bool isExistinHashmap(int data) {
	int hashIdx = getHash(data);
	for (LinkedListNode* currNode = hashmap[hashIdx]; currNode != NULL; currNode = currNode->next) {
		if (currNode->data == data) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int num;
		scanf("%d", &num);
		insertNewNode(num);
	}

	int matched_cnt = 0;
	for (int i = 0; i < m; ++i) {
		int num;
		scanf("%d", &num);
		matched_cnt += isExistinHashmap(num);
	}

	printf("%d", n + m - 2 * matched_cnt);
	return 0;
}