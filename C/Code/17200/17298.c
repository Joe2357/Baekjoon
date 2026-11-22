#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *pNext;
	int index;
} Node;

typedef struct _stack {
	Node *pTop;
	int total_index;
} Stack;

// 스택 초기화
void stack_init(Stack *pStack) {
	pStack->pTop = NULL;

	pStack->total_index = 0;  // index값을 표기하기 위한 변수
}

// 스택이 비었는지 확인
int stack_is_empty(Stack *pStack) {
	if (pStack->pTop == NULL) return SUCCESS;

	return FAIL;
}

// push : top에 데이터 추가
int stack_push(Stack *pStack, Data data) {
	// 새로운 노드 생성
	Node *pNewNode = (Node *)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->data = data;

	pNewNode->pNext = pStack->pTop;
	pStack->pTop = pNewNode;
	pStack->total_index++;
	pStack->pTop->index = pStack->total_index;

	return SUCCESS;
}

// index : stack_top 의 index를 알아내기
int stack_index(Stack *pStack, Data *pData) {
	if (stack_is_empty(pStack)) {
		return FAIL;
	}

	*pData = pStack->pTop->index;

	return SUCCESS;
}

// pop : top의 데이터 꺼내기
int stack_pop(Stack *pStack, Data *pData) {
	if (stack_is_empty(pStack)) {
		return FAIL;
	}

	Node *pCurrent = pStack->pTop;	// 삭제할 노드 기억

	if (pData != NULL)
		*pData = pStack->pTop->data;

	pStack->pTop = pStack->pTop->pNext;	 // top 이동
	free(pCurrent);						 // pop 된 노드 제거

	return SUCCESS;
}

// top : top의 데이터 미리보기
int stack_top(Stack *pStack, Data *pData) {
	if (stack_is_empty(pStack)) {
		return FAIL;
	}

	if (pData != NULL)
		*pData = pStack->pTop->data;  //데이터 읽기(꺼내기)

	return SUCCESS;
}

int AnswerArray[1000005] = {0};

int main() {
	Stack stack;
	Data data;

	stack_init(&stack);

	int SizeofArray = 0;	  // 배열의 크기
	int compareNumber = 0;	  // 비교할 숫자
	int num = compareNumber;  // 간단하게 num이라 지칭
	int topData = 0;		  // top data를 저장할 변수
	int topIndex = 0;		  // top index을 저장할 변수

	scanf("%d", &SizeofArray);

	for (int i = 0; i < SizeofArray; i++) {
		// 1. 수열의 숫자를 차례로 입력받는다.
		scanf("%d", &num);

		// 2. 입력받은 숫자와 stack의 top에 있는 data값과 크기를 비교한다.

		// 2-1. 만약 비교해서 스택이 비어있으면 그냥 num을 stack에 push.

	Recursive_call:

		if (stack_is_empty(&stack)) {
			stack_push(&stack, num);
			continue;
		}

		// 2-2. top data > num 이면 num을 stack에 push.
		stack_top(&stack, &data);
		topData = data;

		if (topData >= num) {
			stack_push(&stack, num);
			continue;
		}

		// 2-3. top data < num 이면, num이 top data의 오큰수가 되는 것.
		// -- 이때 top data의 index값을 저장한다.
		// 이후 정답을 출력할 배열의 index번째에 num값을 넣는다.
		// stack_pop해서 top을 바꿔준다.
		// 다시 2-1로 돌아가서 작업을 수행한다.
		if (topData < num) {
			stack_index(&stack, &data);
			topIndex = data;

			AnswerArray[topIndex] = num;
			stack_pop(&stack, &data);
			goto Recursive_call;
		}
	}

	// TopIndex은 1번째부터 시작, 즉 AnsArray의 0번쨰 배열은 참조하면 안됨

	for (int i = 1; i <= SizeofArray; i++) {
		if (AnswerArray[i] == 0) {
			printf("-1 ");
		} else {
			printf("%d ", AnswerArray[i]);
		}
	}

	return 0;
}