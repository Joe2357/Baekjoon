#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct Bank {
	int x, t, c;
} Bank;
typedef struct MapNode {
	int key;
	ll value;
	struct MapNode* next;
} MapNode;

#define MAX_IDX (int)(3e5)
#define MAP_SIZE (1 << 20)
const ll NONE = -1;

Bank banks[MAX_IDX];
int n;
MapNode* map[MAP_SIZE];

#define max(a, b) ((a) > (b) ? (a) : (b))

int getHash(int key) {
	while (key < 0) {
		key += MAP_SIZE;
	}
	return (key % MAP_SIZE);
}

void insertNewMapNode(int key, ll value) {
	MapNode* newNode = (MapNode*)malloc(sizeof(MapNode));
	newNode->key = key;
	newNode->value = value;
	newNode->next = map[getHash(key)];
	map[getHash(key)] = newNode;
	return;
}

MapNode* find(int key) {
	for (MapNode* cur = map[getHash(key)]; cur != NULL; cur = cur->next) {
		if (cur->key == key) {
			return cur;
		}
	}
	return NULL;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &banks[i].x, &banks[i].t, &banks[i].c);
	}

	ll ret = 0;
	for (int i = 0; i < n; ++i) {
		MapNode* node = find(banks[i].x - banks[i].t);
		ll temp = banks[i].c;

		if (node != NULL) {
			temp += node->value;
			node->value = temp;
		} else {
			insertNewMapNode(banks[i].x - banks[i].t, temp);
		}
		ret = max(ret, temp);
	}

	printf("%lld", ret);
	return 0;
}