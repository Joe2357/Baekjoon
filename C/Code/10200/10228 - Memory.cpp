#include "grader.h"
#include "memory.h"

typedef struct Node {
	int first, second;
} ND;

#define MAX_IDX 25

ND arr[MAX_IDX];

void play() {
	char a;
	for (int i = 1; i <= MAX_IDX * 2; ++i) {
		a = faceup(i);
		if (arr[a - 'A'].first > 0) {
			arr[a - 'A'].second = i;
		} else {
			arr[a - 'A'].first = i;
		}
	}

	for (int i = 0; i < MAX_IDX; ++i) {
		a = faceup(arr[i].first);
		a = faceup(arr[i].second);
	}

	return;
}