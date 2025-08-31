#include <stdio.h>

int original_value;

void read_input() {
	scanf("%d", &original_value);
	return;
}

// 한번의 사이클을 실행
int step(int x) {
	int ten = x % 10;
	int one = ((x / 10) + (x % 10)) % 10;

	return ten * 10 + one;
}

int main() {
	read_input();

	int current_value = original_value;
	int ret = 0;

	// 사이클 수행
	do {
		current_value = step(current_value);
		++ret;
	} while (original_value != current_value);

	printf("%d", ret);
	return 0;
}