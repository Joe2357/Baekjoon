#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 8
#define MAX_OPERATION 10
const int DIGIT = 10;
const int NONE = -1;

typedef struct Operation {
	int l, r, c;
} Operation;
typedef struct TrieNode {
	struct TrieNode* link[MAX_IDX]; // state 값을 역순으로 해서 순회하도록 구성
	int value;
} TrieNode;
typedef struct HeapNode {
	int state;
	int cost;
} HeapNode;

int arr[MAX_IDX];
Operation op[MAX_OPERATION]; // 간선 역할
int n, m;
HeapNode heap[200000]; // 8! 이상 임의 설정
int heapSize = 0;
TrieNode* root;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		op[i] = (Operation){l, r, c};
	}
	return;
}

TrieNode* createNewNode() {
	TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
	for (int i = 0; i < MAX_IDX; ++i) {
		newNode->link[i] = NULL;
	}
	newNode->value = NONE;
	return newNode;
}

void init() {
	root = createNewNode();
	return;
}

bool isSorted(int v) {
	bool ret = true;
	for (int i = 1; i < n; ++i) {
		int cur = v % DIGIT;
		v /= DIGIT;
		int next = v % DIGIT;
		ret &= (arr[next] <= arr[cur]); // 비내림차순 확인
	}
	return ret;
}

TrieNode* getStateNode(int x) {
	TrieNode* cur = root;
	for (int i = 0; i < n; ++i) {
		int next_idx = x % DIGIT;
		if (cur->link[next_idx] == NULL) {
			cur->link[next_idx] = createNewNode();
		}
		cur = cur->link[next_idx];
		x /= DIGIT;
	}
	return cur;
}

void insertHeap(int state, int cost) {
	int i = ++heapSize;
	while (i != 1 && cost < heap[i / 2].cost) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = (HeapNode){state, cost};
}

HeapNode popHeap() {
	int parent, child;
	HeapNode item, temp;
	item = heap[1];
	temp = heap[heapSize--];
	parent = 1;
	child = 2;
	while (child <= heapSize) {
		if (child < heapSize && heap[child].cost > heap[child + 1].cost)
			child++;
		if (temp.cost <= heap[child].cost)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

bool isHeapEmpty() {
	return heapSize == 0;
}

int execute_operate(int s, int l, int r) {
	int temp[MAX_IDX];
	int next_s = 0;

	// 정수 상태를 배열로 변환 (뒤에서부터 추출)
	for (int i = n - 1; i >= 0; --i) {
		temp[i] = s % DIGIT;
		s /= DIGIT;
	}

	// l번째 인덱스와 r번째 인덱스의 값 교환
	int t = temp[l - 1];
	temp[l - 1] = temp[r - 1];
	temp[r - 1] = t;

	// 배열을 다시 정수 상태로 변환
	for (int i = 0; i < n; ++i) {
		next_s = next_s * DIGIT + temp[i];
	}

	return next_s;
}

int solve() {
	// 초기 상태 : 01234567
	int init_state = 0;
	for (int i = 0; i < n; ++i) {
		init_state = init_state * DIGIT + i;
	}

	// 다익스트라 초기설정
	TrieNode* s = getStateNode(init_state);
	s->value = 0;
	insertHeap(init_state, 0);

	while (isHeapEmpty() == false) {
		HeapNode cur = popHeap();
		TrieNode* map_node = getStateNode(cur.state);

		if (map_node->value != NONE && map_node->value < cur.cost) {
			continue;
		} else if (isSorted(cur.state) == true) {
			return cur.cost;
		}

		for (int i = 0; i < m; ++i) {
			int next_state = execute_operate(cur.state, op[i].l, op[i].r);
			int next_cost = cur.cost + op[i].c;

			TrieNode* candidate = getStateNode(next_state);
			if (candidate->value == NONE || candidate->value > next_cost) {
				/*
				printf("==============\n");
				printf(" current state : %d\n", cur.state);
				printf(" using operation %d : (%d %d %d)\n", i, op[i].l, op[i].r, op[i].c);
				printf(" next state : %d, next cost : %d\n", next_state, next_cost);
				printf("==============\n\n");
				*/
				candidate->value = next_cost;
				insertHeap(next_state, next_cost);
			}
		}
	}

	return NONE;
}

int main() {
	read_input();
	init();
	printf("%d", solve());
	return 0;
}