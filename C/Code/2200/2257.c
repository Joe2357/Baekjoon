#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 100
const int HYDROGEN = 1;
const int CARBON = 12;
const int OXYGEN = 16;
const char ARBITARY_CHAR = 'X';

char str[MAX_LEN + 1];
char stack[MAX_LEN + 1];
int int_stack[MAX_LEN + 1];
int stack_top, int_stack_top;

void init() {
	stack_top = int_stack_top = -1;
	return;
}

bool isCharStackEmpty() {
	return (stack_top == -1);
}
bool isIntStackEmpty() {
	return (int_stack_top == -1);
}
void push_char(char x) {
	stack[++stack_top] = x;
	return;
}
void push_int(int x) {
	int_stack[++int_stack_top] = x;
	return;
}
char pop_char() {
	return stack[stack_top--];
}
int pop_int() {
	return int_stack[int_stack_top--];
}

void debug(int index, char current_char) {
	printf("\n--- Step %d: Processing '%c' ---\n", index, current_char);

	printf("Char Stack (top: %d): ", stack_top);
	if (stack_top == -1)
		printf("Empty");
	for (int i = 0; i <= stack_top; i++) {
		printf("[%c] ", stack[i]);
	}
	printf("\n");

	printf("Int Stack  (top: %d): ", int_stack_top);
	if (int_stack_top == -1)
		printf("Empty");
	for (int i = 0; i <= int_stack_top; i++) {
		printf("[%d] ", int_stack[i]);
	}
	printf("\n------------------------------\n");
	return;
}

int main() {
	init();
	scanf("%s", str);
	// printf("input string :: %s\n", str);

	for (int i = 0; str[i] != '\0'; ++i) {
		switch (str[i]) {
			case '(': {
				push_char('(');
				break;
			}
			case ')': {
				int temp = 0;
				while (isCharStackEmpty() == false) {
					char cur_c = pop_char();
					if (cur_c == '(') {
						break;
					}
					temp += pop_int();
				}
				push_char(ARBITARY_CHAR);
				push_int(temp);
				break;
			}
			case 'H': {
				push_char('H');
				push_int(HYDROGEN);
				break;
			}
			case 'C': {
				push_char('C');
				push_int(CARBON);
				break;
			}
			case 'O': {
				push_char('O');
				push_int(OXYGEN);
				break;
			}
			default: { // 숫자 입력
				if (isIntStackEmpty() == false) {
					int temp = pop_int();
					push_int(temp * (str[i] - '0'));
				}
				break;
			}
		}

		// debug(i, str[i]);
	}

	int ret = 0;
	while (isIntStackEmpty() == false) {
		ret += pop_int();
	}
	printf("%d", ret);
	return 0;
}