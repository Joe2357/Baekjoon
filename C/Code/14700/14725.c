#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_ALPHABET 26
#define MAX_FOOD_LEN 15

typedef struct TrieNode {
	char food_name[MAX_FOOD_LEN + 1];	  // 음식 이름
	struct TrieNode* child[MAX_ALPHABET]; // 자식 포인터 배열
	struct TrieNode* sibling;			  // 본인의 옆 노드
} TrieNode;

TrieNode* root; // 루트는 아무 문자열도 존재하지 않으며, 출력도 없어야 함
int n;

TrieNode* createNewTrieNode() {
	TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
	for (int i = 0; i < MAX_ALPHABET; ++i) {
		newNode->child[i] = NULL;
	}
	newNode->sibling = NULL;
	return newNode;
}
TrieNode* findNode(TrieNode* cur, char* food) {
	// 현재 위치 cur에서 child의 음식 이름이 food인 노드 찾기
	// 만약 보유하고 있지 않다면 NULL 반환
	for (TrieNode* temp = cur->child[food[0] - 'A']; temp != NULL; temp = temp->sibling) {
		if (strcmp(temp->food_name, food) == 0) { // child가 존재하며 찾음
			return temp;
		}
	}
	return NULL; // child가 존재하지 않음
}
void insertNewTrieNode(TrieNode* cur, TrieNode* newNode) {
	// newNode를 trie 자료구조에 접합시킴
	// 이 때, trie를 연결하는 기준은 food의 앞글자임
	// 같은 앞글자를 가진 child food들도 여러개 존재할 수 있으며, 이 때 list는 사전순을 유지해야함
	// 즉, 연결리스트에 삽입정렬을 시도해야할 듯
	int idx = newNode->food_name[0] - 'A';
	TrieNode** target = &(cur->child[idx]);

	// 삽입정렬 (자리 찾기)
	while (*target != NULL && strcmp((*target)->food_name, newNode->food_name) < 0) {
		target = &((*target)->sibling);
	}
	// 삽입정렬 (위치 특정 및 삽입)
	newNode->sibling = *target;
	*target = newNode;

	return;
}

void read_input() {
	root = createNewTrieNode();

	scanf("%d", &n);
	while (n--) {
		int k;
		scanf("%d", &k);

		// 입력 문자열 삽입
		TrieNode* cur = root;
		for (int i = 0; i < k; ++i) {
			char food[MAX_FOOD_LEN + 1];
			scanf("%s", food);

			TrieNode* next = findNode(cur, food);
			if (next == NULL) { // 아직 그 음식이 포함되지 않음
				TrieNode* newNode = createNewTrieNode();
				strcpy(newNode->food_name, food);
				insertNewTrieNode(cur, newNode);
				cur = newNode;
			} else {
				cur = next;
			}
		}
	}
	return;
}

void inorder_traverse(TrieNode* node, int lv) {
	// 현재 노드 출력 (루트 제외)
	if (lv >= 0) {
		for (int i = 0; i < lv; ++i) {
			printf("--");
		}
		printf("%s\n", node->food_name);
	}

	// 자식 노드 순회 :: 각 알파벳(A~Z) 버킷을 확인
	for (int i = 0; i < MAX_ALPHABET; ++i) {
		TrieNode* currChild = node->child[i];

		// 해당 알파벳으로 시작하는 자식이 있다면, 연결된 모든 sibling을 순회해야 함
		while (currChild != NULL) {
			inorder_traverse(currChild, lv + 1);
			currChild = currChild->sibling;
		}
	}
	return;
}

int main() {
	read_input(); // init();
	inorder_traverse(root, -1);
	return 0;
}