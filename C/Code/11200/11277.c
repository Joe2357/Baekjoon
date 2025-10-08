#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Clause {
	int first, second;
} CL;

#define MAX_IDX 20
#define MAX_CLAUSE 100

int n, m;
bool variable[MAX_IDX + 1 + 1];
bool isAnswerExists;
CL clause[MAX_CLAUSE];

#define abs(x) (((x) < 0) ? (-(x)) : (x))

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		clause[i] = (CL){a, b};
	}
	return;
}

void print_result() {
	if (isAnswerExists == true) {
		printf("1");
	} else {
		printf("0");
	}
	return;
}

bool check() {
	bool ret = true;
	for (int i = 0; i < m; ++i) {
		int l = clause[i].first, r = clause[i].second;
		ret &= (((l > 0 && variable[abs(l)] == true) || (l < 0 && variable[abs(l)] == false)) || ((r > 0 && variable[abs(r)] == true) || (r < 0 && variable[abs(r)] == false)));
	}
	return ret;
}

void solve(int x) {
	if (isAnswerExists == true) {
		return;
	} else if (x == n) {
		if (check() == true) {
			isAnswerExists = true;
			return;
		} else {
			return;
		}
	} else {
		solve(x + 1); // variable[x + 1] = false
		variable[x + 1] = true;
		solve(x + 1); // variable[x + 1] = true
		variable[x + 1] = false;
	}

	return;
}

int main() {
	read_input();
	solve(0);
	print_result();
	return 0;
}