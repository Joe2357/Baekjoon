#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;

#define HASH_SIZE 10003
#define MAX_OPERATION 30
const ll NONE = -1LL;
const ll DIGIT = 10LL;

// c로 map 지원좀 해줘..
typedef struct HashNode {
	ll v;
	struct HashNode* next;
} HashNode;

HashNode* visit[MAX_OPERATION + 1][HASH_SIZE];
ll upper_bound;
int d, p;

#define max(a, b) (((a) > (b)) ? (a) : (b))

unsigned int get_hash(ll v) {
	return (unsigned int)(v % HASH_SIZE);
}

bool check_and_mark(int op, ll v) {
	// 2번 순회하지 말고, 방문과 체크를 동시에 진행
	unsigned int key = get_hash(v);

	for (HashNode* node = visit[op][key]; node != NULL; node = node->next) {
		if (node->v == v) { // 이미 방문함
			return true;
		}
	}

	// 방문한 적이 없는 경우 노드 추가
	HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
	newNode->v = v;
	newNode->next = visit[op][key], visit[op][key] = newNode;
	return false;
}

ll solve(ll v, int op) {
	if (v >= upper_bound) { // 값의 범위를 넘어섬
		return NONE;
	} else if (op == 0) { // 모든 연산을 완료하였고, valid함
		return v;
	} else if (check_and_mark(op, v) == true) { // 이미 방문한 경로임
		return NONE;
	}

	ll ret = NONE;
	for (ll i = 2; i <= 9; ++i) {
		ll subresult = solve(v * i, op - 1);
		ret = max(ret, subresult);
	}
	return ret;
}

int main() {
	scanf("%d %d", &d, &p);
	upper_bound = 1LL;
	while (d--) {
		upper_bound *= DIGIT;
	}

	// 경우의 수가 8^30이므로, 절대 시간 안에 돌 수 없음
	printf("%lld", solve(1LL, p));
	return 0;
}