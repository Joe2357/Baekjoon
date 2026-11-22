#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

#define MAX_COMMAND (int)(1e5)
#define COMMAND_LEN 4
#define MAX_SIZE 1000
#define TOP_INITIAL_VALUE -1
const ll INF = (ll)(1e9);

bool exit_command, isError;
ll stack[MAX_SIZE];
int top = TOP_INITIAL_VALUE;
char command[MAX_COMMAND + 1][COMMAND_LEN + 1];
int command_count;
int num_queue[MAX_COMMAND + 1], num_count;

#define abs(x) ((x) < 0 ? -(x) : (x))

void init() {
	top = TOP_INITIAL_VALUE;
	command_count = 0;
	num_count = 0;
	exit_command = false;
	isError = false;
	return;
}
void clearStack() {
	top = TOP_INITIAL_VALUE;
	isError = false;
	return;
}
void read_command() {
	while (true) {
		scanf("%s", command[command_count]);
		if (command[command_count][0] == 'Q') {
			exit_command = true;
			break;
		} else if (command[command_count][0] == 'E') {
			break;
		} else if (command[command_count][0] == 'N') {
			ll x;
			scanf("%lld", &x);
			num_queue[num_count++] = x;
		}
		command_count++;
	}
	return;
}

bool isStackEmpty() {
	return top == TOP_INITIAL_VALUE;
}
int len() {
	return top + 1;
}
void push(ll x) {
	stack[++top] = x;
	return;
}
ll pop() {
	if (isStackEmpty() == true) {
		isError = true;
		return 0LL;
	}
	return stack[top--];
}

void print_stack() {
	printf("len : %d\n", len());
	for (int i = 0; i <= top; ++i) {
		printf("%lld ", stack[i]);
	}
	printf("\n");
	return;
}

void process() {
	int num_index = 0;
	for (int i = 0; i < command_count && isError == false; ++i) {
		switch (command[i][0]) {
			case 'N': { // NUM
				push(num_queue[num_index++]);
				break;
			}
			case 'P': { // POP
				ll tmp = pop();
				break;
			}
			case 'I': { // INV
				ll x = pop();
				push(-x);
				break;
			}
			case 'D': {
				if (command[i][1] == 'U') { // DUP
					ll x = pop();
					push(x);
					push(x);
					break;
				} else if (command[i][1] == 'I') { // DIV
					ll x1 = pop();
					ll x2 = pop();
					if (x1 == 0) {
						isError = true;
						break;
					}
					ll res = x2 / x1;
					if (abs(res) > INF) {
						isError = true;
						break;
					}
					push(res);
					break;
				}
			}
			case 'S': {
				if (command[i][1] == 'W') { // SWP
					ll x1 = pop();
					ll x2 = pop();
					push(x1);
					push(x2);
					break;
				} else if (command[i][1] == 'U') { // SUB
					ll x1 = pop();
					ll x2 = pop();
					ll res = x2 - x1;
					if (abs(res) > INF) {
						isError = true;
						break;
					}
					push(res);
					break;
				}
			}
			case 'A': { // ADD
				ll x1 = pop();
				ll x2 = pop();
				ll res = x1 + x2;
				if (abs(res) > INF) {
					isError = true;
					break;
				}
				push(res);
				break;
			}
			case 'M': {
				if (command[i][1] == 'U') { // MUL
					ll x1 = pop();
					ll x2 = pop();
					ll res = x1 * x2;
					if (abs(res) > INF) {
						isError = true;
						break;
					}
					push(res);
					break;
				} else if (command[i][1] == 'O') { // MOD
					ll x1 = pop();
					ll x2 = pop();
					if (x1 == 0) {
						isError = true;
						break;
					}
					ll res = x2 % x1;
					if (abs(res) > INF) {
						isError = true;
						break;
					}
					push(res);
					break;
				}
			}
		}

		// print_stack();
	}

	if (len() != 1) {
		isError = true;
	}
	return;
}

int main() {
	while (true) {
		init();
		read_command();
		if (exit_command == true) {
			break;
		}

		int n;
		scanf("%d", &n);
		while (n--) {
			ll x;
			scanf("%lld", &x);

			clearStack();
			push(x);

			process();

			if (isError == true) {
				printf("ERROR\n");
			} else {
				printf("%lld\n", stack[0]);
			}
		}
		printf("\n");
	}
	return 0;
}