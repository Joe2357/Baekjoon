#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 9
#define MAX_OPERATORS 3

const char operators[MAX_OPERATORS] = {' ', '+', '-'};

bool is_valid_expression(int n, char* expression) {
	// 표현된 expression이 0이 되는지 확인

	int ret = 0, temp = 1, current = 1;
	for (int i = 0; i < n; ++i) { // 연산자 갯수만큼 반복
		current += 1;			  // 현재 숫자 증가
		switch (expression[i]) {
			case '+': {
				ret += temp;
				temp = current;
				break;
			}
			case '-': {
				ret += temp;
				temp = -current;
				break;
			}
			case ' ': {
				temp = temp * 10;
				if (temp > 0) {
					temp += current;
				} else {
					temp -= current;
				}
				break;
			}
		}
	}
	ret += temp;
	return (ret == 0);
}

void print_expression(int n, char* expression) {
	for (int i = 0; i < n; ++i) {
		printf("%d%c", i + 1, expression[i]);
	}
	printf("%d\n", n + 1);
	return;
}

void backtrack(int idx, int n, char* expression) {
	if (idx == n) {
		if (is_valid_expression(n, expression) == true) {
			print_expression(n, expression);
		}
		return;
	}

	for (int i = 0; i < MAX_OPERATORS; ++i) {
		expression[idx] = operators[i];
		backtrack(idx + 1, n, expression);
		// expression[idx] = '\0';
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		char expression[MAX_IDX + 1];
		backtrack(0, n - 1, expression); // 숫자가 7개면 연산자는 6개이므로 n - 1
		printf("\n");
	}
	return 0;
}