#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 1000
#define MOD (int)(1e5 + 7)

typedef struct LinkedListNode {
	int start;
	int length;
	struct LinkedListNode* next;
} LinkedListNode;

char str[MAX_LEN + 1];
int prefix[MAX_LEN + 1];
int pow31[MAX_LEN + 1];
LinkedListNode* hashTable[MOD] = {NULL};

int getHash(const char* s, int length) {
	int start = (int)(s - str);
	int end = start + length;
	int hashValue = prefix[end] - (int)(1LL * prefix[start] * pow31[length] % MOD);
	if (hashValue < 0) {
		hashValue += MOD;
	}
	return hashValue;
}

bool contains(int hashValue, const char* key, int length) {
	for (LinkedListNode* node = hashTable[hashValue]; node != NULL; node = node->next) {
		if (node->length != length) {
			break;
		} else if (strncmp(str + node->start, key, length) == 0) {
			return true;
		}
	}
	return false;
}

void insert(int hashValue, const char* key, int length) {
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode->start = (int)(key - str);
	newNode->length = length;
	newNode->next = hashTable[hashValue];
	hashTable[hashValue] = newNode;
	return;
}

int main() {
	scanf("%s", str);
	int len = strlen(str);

	pow31[0] = 1;
	for (int i = 1; i <= len; ++i) {
		pow31[i] = (int)((1LL * pow31[i - 1] * 31) % MOD);
	}

	prefix[0] = 0;
	for (int i = 0; i < len; ++i) {
		prefix[i + 1] = (int)((1LL * prefix[i] * 31 + (str[i] - 'a' + 1)) % MOD);
	}

	int ret = 0;
	for (int current_length = 1; current_length <= len; ++current_length) {
		for (int start = 0; start <= len - current_length; ++start) {
			int hashValue = getHash(&str[start], current_length);
			if (contains(hashValue, &str[start], current_length) == false) {
				ret += 1;
				insert(hashValue, &str[start], current_length);
			}
		}
	}

	printf("%d", ret);
	return 0;
}
