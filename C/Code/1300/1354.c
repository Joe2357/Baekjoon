#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;
#define NONE -1
#define TABLE_SIZE 1000003LL
ll p, q, x, y;

typedef struct HashNode {
	ll key;
	ll value;
	struct HashNode* next;
} HashNode;
typedef struct HashNodeList {
	HashNode* head;
} HashNodeList;

HashNodeList table[TABLE_SIZE];

ll getHash(ll n) {
	return n % TABLE_SIZE;
}

ll find(ll n) {
	for (HashNode* cur = table[getHash(n)].head; cur != NULL; cur = cur->next) {
		if (cur->key == n) {
			return cur->value;
		}
	}
	return NONE;
}

void save(ll n, ll value) {
	ll idx = getHash(n);
	HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
	newNode->key = n;
	newNode->value = value;
	newNode->next = table[idx].head;
	table[idx].head = newNode;
	return;
}

ll solve(ll n) {
	ll ret;
	if (n <= 0) {
		return 1;
	} else if ((ret = find(n)) != NONE) {
		return ret;
	} else {
		ret = solve(n / p - x) + solve(n / q - y);
		save(n, ret);
		return ret;
	}
}

int main() {
	ll n;
	scanf("%lld %lld %lld %lld %lld", &n, &p, &q, &x, &y);
	printf("%lld", solve(n));
	return 0;
}
