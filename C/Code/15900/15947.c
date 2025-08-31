#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_WORDS 14
#define MAX_LEN 10
const int MAX_LOOP_CNT = 5;

int main() {
	char song[MAX_WORDS][MAX_LEN] = {
		"sukhwan",
		"baby",
		"sukhwan",
		"tururu",
		"turu",
		"very",
		"cute",
		"tururu",
		"turu",
		"in",
		"bed",
		"tururu",
		"turu",
		"baby",
	};
	bool isNotLoop[MAX_WORDS + 1] = {
		true, true, true, false, false,
		true, true, false, false, true,
		true, false, false, true};

	int n;
	scanf("%d", &n);
	int target_word = n % MAX_WORDS;

	if (isNotLoop[target_word] == true)
		printf("%s", song[target_word]);
	else {
		int loop_cnt = n / MAX_WORDS + 1;
		if (n % 2 > 0) {
			++loop_cnt;
		}
		if (loop_cnt < MAX_LOOP_CNT) {
			printf("tu");
			for (; loop_cnt > 0; --loop_cnt)
				printf("ru");
		} else
			printf("tu+ru*%d", loop_cnt);
	}
}