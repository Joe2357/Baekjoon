#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_INDEX 1000000

using namespace std;

char str[MAX_INDEX + 1], target[37], stack[MAX_INDEX + 1];
int top, target_length;

bool check() {
	// length check
	if (top < target_length)
		return false;

	// string compare
	for (int i = top - target_length, j = 0; i < top; i++, j++)
		if (stack[i] != target[j]) // something isn't same
			return false;

	// string compare result is true
	return true;
}

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	cin >> str >> target;
	target_length = strlen(target);

	// stack operation
	for (int i = 0; str[i] != '\0'; i++) {
		stack[top++] = str[i];
		if (check())
			top -= target_length;
	}

	// print result
	if (top != 0) {
		stack[top++] = '\0';
		cout << stack;
	}
	else
		cout << "FRULA";
	return 0;
}