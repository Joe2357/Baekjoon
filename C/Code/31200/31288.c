#include <stdio.h>

#define MAX_LEN 100

char p[MAX_LEN + 1];
int n;

void read_input() {
	scanf("%d %s", &n, p);
	return;
}

void solve() {
	// n = 1일때의 예외처리를 해주자. 아래 코드로도 답을 구할 수는 있는데, R < Q 조건이 있네;
	if (n == 1) {
		printf("9 3\n");
		return;
	}

	// 모두 3의 배수로 만들면 되지 않을까?
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (p[i] - '0');
	}

	int need = 3 - (sum % 3); // sum은 3의 배수일 리가 없음
	for (int i = 0; i < n; ++i) {
		char original = p[i];

		int temp = p[i] - '0';
		temp = (temp + need >= 10) ? temp - (3 - need) : temp + need;
		p[i] = temp + '0';
		printf("%s 3\n", p);
		p[i] = original;
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		read_input();
		solve();
	}
	return 0;
}