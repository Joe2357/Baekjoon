#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
#define MAX_LEN 80
#define ALPHABET_SIZE 26

typedef struct Word {
	char str[MAX_LEN + 1];
	int length;
} Word;

Word words[MAX_IDX + 1]; // start = 0
int d;

int queue[MAX_IDX + 1];
bool visited[MAX_IDX + 1 + 1];
int front, rear;

void read_input() {
	scanf("%d", &d);
	for (int i = 0, j; i <= d; ++i) {
		scanf("%s", words[i].str);
		words[i].length = strlen(words[i].str);
		visited[i] = false;
	}
	return;
}

bool only_one_more(int longer_idx, int shorter_idx) {
	char* L = words[longer_idx].str;
	char* S = words[shorter_idx].str;

	bool skipped = false;
	for (int i = 0, j = 0; i < words[longer_idx].length && j < words[shorter_idx].length; ++i, ++j) {
		if (L[i] != S[j]) {
			if (skipped == true) {
				return false;
			} else {
				skipped = true;
				j -= 1;
			}
		}
	}

	return true;
}

int main() {
	read_input();

	int ret = 0;
	front = rear = 0;

	visited[0] = true;
	queue[rear++] = 0;

	while (front < rear) {
		int curr = queue[front++];
		ret = curr;

		for (int i = 1; i <= d; ++i) {
			if ((visited[i] == false) && (words[i].length == words[curr].length + 1)) {
				if (only_one_more(i, curr) == true) {
					visited[i] = true;
					queue[rear++] = i;
				}
			}
		}
	}

	printf("%s", words[ret].str);
	return 0;
}