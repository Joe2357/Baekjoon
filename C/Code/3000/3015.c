#include <stdbool.h>
#include <stdio.h>

typedef unsigned long long ull;

#define MAX_IDX (int)(5e5)

typedef struct StackNode {
	int v;
	int cnt;
} SN;

typedef struct Stack {
	SN arr[MAX_IDX + 1];
	int l;
} Stack;

Stack s;
int n;

bool isStackEmpty() {
	return (s.l == 0);
}
ull getLength() {
	return (ull)s.l;
}
void push(int x, int cnt) {
	s.arr[s.l++] = (SN){x, cnt};
	return;
}
SN pop() {
	s.l -= 1;
	return s.arr[s.l];
}

int main() {
	scanf("%d", &n);
	s.l = 0;

	ull ret = 0ULL;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);

		int new_cnt = 1;
		while (isStackEmpty() == false) { // 이 스택은 내림차순으로 되어있음
			int top = s.arr[s.l - 1].v;	  // 스택의 제일 위 확인
			if (top < x) {				  // top은 이후부터는 x에 의해 가려지므로, 쌍을 이룰 수 없음
				SN temp = pop();		  // 하지만 현재 x와는 쌍을 이루었음
				ret += (ull)(temp.cnt);
			} else if (top > x) { // 여기서 종료되어야 함
				ret += 1ULL;	  // 가장 뒤 1개는 쌍으로 이어줄 수 있음
				break;
			} else { // 둘이 같은 경우, 원소는 빼지 않으면서 탐색은 계속 이어나가야 함
				SN temp = pop();
				ret += (ull)(temp.cnt); // pair는 이만큼 만들 수 있음
				new_cnt = temp.cnt + 1; // 즉, 구조체를 합쳐버릴 예정임
			}
		}
		push(x, new_cnt);
	}
	printf("%llu", ret);
	return 0;
}