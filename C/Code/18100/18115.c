#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
	int number;
	struct Card* next;
} Card;

#define MAX_IDX (int)(1e6)
const int START = 1;

int actions[MAX_IDX];
int n;

Card* card_deck;
Card* card_tale;

Card* createNewNode(int x) {
	Card* newNode = (Card*)malloc(sizeof(Card));
	newNode->number = x;
	newNode->next = NULL;
	return newNode;
}

void init() {
	Card* first_node = createNewNode(START);
	card_deck = first_node;
	card_tale = first_node;
	return;
}

void print_result() {
	Card* current_ptr = card_deck;
	while (current_ptr != NULL) {
		printf("%d ", current_ptr->number);
		current_ptr = current_ptr->next;
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", actions + i);
	}

	init(); // 카드 덱 초기화 (카드 1은 매번 가장 마지막에 1번 action을 통해 내려짐)

	for (int card_number = START + 1; card_number <= n; ++card_number) {
		Card* newNode = createNewNode(card_number);
		
		switch (actions[n - card_number]) { // 입력의 역순으로 처리
			case 1: { // 제일 위의 카드를 바닥에 내려놓음
				newNode->next = card_deck;
				card_deck = newNode;
				break;
			}
			case 2: { // 위에서 2번째의 카드를 바닥에 내려놓음
				newNode->next = card_deck->next;
				card_deck->next = newNode;
				if (newNode->next == NULL) {
					card_tale = newNode;
				}
				break;
			}
			case 3: { // 제일 밑의 카드를 바닥에 내려놓음
				card_tale->next = newNode;
				card_tale = newNode;
				break;
			}
		}
	}

	print_result();
	return 0;
}