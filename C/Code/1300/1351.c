#include <stdio.h>
#include <stdlib.h>

const int NONE = -1;

typedef long long lld;
typedef struct Node {
	lld key;
	lld v;
	struct Node* next;
} ND;

// Linked List
ND* head = NULL;

void insert(lld key, lld v) {
	ND* newNode = (ND*)malloc(sizeof(ND));
	newNode->key = key, newNode->v = v;
	newNode->next = head;
	head = newNode;
	return;
}
lld find(lld key) {
	ND* current = head;
	while (current != NULL) {
		if (current->key == key) {
			return current->v;
		}
		current = current->next;
	}
	return NONE;
}

lld solve(lld n, lld p, lld q) {
	lld ret;

	if (n == 0) {
		return 1;
	} else if ((ret = find(n)) != NONE) {
		return ret;
	} else {
		lld left = n / p, right = n / q;
		ret = solve(left, p, q) + solve(right, p, q);

		insert(n, ret);
		return ret;
	}
}

int main() {
	lld n, p, q;
	scanf("%lld %lld %lld", &n, &p, &q);
	printf("%lld", solve(n, p, q));
	return 0;
}