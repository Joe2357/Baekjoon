#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct MapNode {
	int key;
	int cnt;
	struct MapNode* next;
} MapNode;

#define MAX_IDX (int)(1e5)
#define MAP_SIZE (int)(1e5 + 1)

int arr[MAX_IDX];
int n, x;
ll ret;
MapNode* map[MAP_SIZE];

int getHash(int key) {
	return (key % MAP_SIZE);
}

void init() {
	ret = 0;
	for (int i = 0; i < MAP_SIZE; ++i) {
		map[i] = NULL;
	}
	return;
}

MapNode* find(int key) {
	for (MapNode* node = map[getHash(key)]; node != NULL; node = node->next) {
		if (node->key == key) {
			return node;
		}
	}
	return NULL;
}

void insertNewMapNode(int key) {
	int hash = getHash(key);
	MapNode* newNode = (MapNode*)malloc(sizeof(MapNode));
	newNode->key = key;
	newNode->cnt = 1;
	newNode->next = map[hash];
	map[hash] = newNode;
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d %d", &n, &x);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			MapNode* node = find(arr[i]);

			if (node == NULL) {
				insertNewMapNode(arr[i]);
			} else {
				node->cnt += 1;
			}
		}

		for (int i = 0; i < n; ++i) {
			int cur = arr[i];
			MapNode* nodeCur = find(cur);

			if (nodeCur->cnt != 0) {
				if (x == 0) {
					ll cnt = nodeCur->cnt;
					ret += (cnt * (cnt - 1) / 2);
				} else {
					int target = cur ^ x;
					MapNode* nodeTarget = find(target);

					if (nodeTarget != NULL && nodeTarget->cnt != 0) {
						ret += ((ll)nodeCur->cnt * (ll)nodeTarget->cnt);
					}
				}

				nodeCur->cnt = 0; // 노드 없애기
			}
		}

		printf("%lld\n", ret);
	}
	return 0;
}