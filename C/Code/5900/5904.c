#include <stdio.h>

#define MAX_LEN (int)(1e9)
#define MAX_STEP 30 // sequence 30은 10^9보다 길다
const int END_OF_STEP = 1;

int length_of_sequence[MAX_STEP + 1];

void init() {
	length_of_sequence[1] = 3; // "moo"
	for (int i = 2; length_of_sequence[i - 1] <= MAX_LEN; ++i) {
		length_of_sequence[i] = length_of_sequence[i - 1] * 2 + (i + 2);
	}
	return;
}

char solve(int idx, int step) {
	if (step == END_OF_STEP) {
		// 맨 앞글자를 제외하고는 모두 o이다.
		return ((idx == 0) ? 'm' : 'o');
	} else {
		int length_of_previous_step = length_of_sequence[step - 1];
		int length_of_current_step = length_of_sequence[step];
		if (idx < length_of_previous_step) { // 분할 가능한 부분의 앞쪽인 경우
			return solve(idx, step - 1);
		} else if (length_of_current_step - idx <= length_of_previous_step) { // 분할 가능한 부분의 뒤쪽인 경우
			return solve(idx + length_of_previous_step - length_of_current_step, step - 1);
		} else { // 중간 부분인 경우
			return ((idx - length_of_previous_step == 0) ? 'm' : 'o');
		}
	}
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	printf("%c", solve(n - 1, MAX_STEP));
	return 0;
}