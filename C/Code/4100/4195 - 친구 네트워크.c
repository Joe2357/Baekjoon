#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 21
#define PRI 100003
#define MAX_PEO 210000
typedef char boolean;
#define True 1
#define False 0

typedef struct HashNode {
	char name[MAX_LEN];
	int num;
	struct HashNode* next;
} HN;
typedef struct Node {
	int parent;
	int num;
} ND;

HN* hash[PRI];
ND parent[MAX_PEO];
int userLen;

int getHash(char* name) {
	int retval = 0;
	for (int i = 0; name[i]; ++i) {
		retval = (retval * 100 + name[i]) % PRI;
	}
	return retval;
}

int search(char* name) {
	int val = getHash(name);
	HN* ptr = hash[val];
	while (ptr) {
		if (!strcmp(ptr->name, name)) {
			return ptr->num;
		}
		ptr = ptr->next;
	}
	return -1;
}

void insertHash(char* name) {
	int val = getHash(name);
	HN* ptr = hash[val];
	HN* newNode = (HN*)malloc(sizeof(HN));
	strcpy(newNode->name, name);
	newNode->num = userLen;
	parent[userLen] = (ND) { userLen, 1 };
	newNode->next = ptr;
	hash[val] = newNode;
	// printf("%s : %d\n", name, userLen);
	return;
}

int find(int x) {
	if (parent[x].parent == x) {
		return x;
	}
	else {
		return parent[x].parent = find(parent[x].parent);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		userLen = 0;
		for (int i = 0; i < PRI; ++i) {
			hash[i] = NULL;
		}

		while (n--) {
			char str1[MAX_LEN], str2[MAX_LEN];
			scanf("%s %s", str1, str2);
			int p1 = search(str1), p2 = search(str2);
			if (p1 == -1) {
				insertHash(str1);
				p1 = userLen++;
			}
			if (p2 == -1) {
				insertHash(str2);
				p2 = userLen++;
			}

			int x = find(p1), y = find(p2);
			if (x != y) {
				if (x > y) {
					int temp = x;
					x = y, y = temp;
				}

				parent[x].num += parent[y].num;
				parent[y].parent = x;
				printf("%d\n", parent[x].num);
			}
			else {
				printf("%d\n", parent[x].num);
			}
		}
	}

	return 0;
}