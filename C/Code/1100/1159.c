#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define LENGTH_OF_ALPHABET 26
#define MAX_LEN 30
const int TARGET_NUMBER = 5;

int count[LENGTH_OF_ALPHABET];
char name[MAX_LEN + 1];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		count[name[0] - 'a'] += 1; // 앞글자만 확인
	}

	bool isAnswerExists = false;
	for (int i = 0; i < LENGTH_OF_ALPHABET; i++) {
		if (count[i] >= TARGET_NUMBER) {
			printf("%c", i + 'a');
			isAnswerExists = true;
		}
	}

	if (isAnswerExists == false) {
		printf("PREDAJA");
	}
	return 0;
}