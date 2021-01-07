#include <stdio.h>

typedef struct Node {
	int count, pre;
} ND;

#define MAX_INDEX (int)1e6
#define END -1
ND arr[MAX_INDEX + 1] = { {0, 0}, {0, END} };

void init() {
	for (int i = 2; i <= MAX_INDEX; ++i) {
		arr[i].count = MAX_INDEX;
		if (i % 3 == 0 && arr[i / 3].count + 1 < arr[i].count)
			arr[i] = (ND) { arr[i / 3].count + 1, i / 3 };
		if (i % 2 == 0 && arr[i / 2].count + 1 < arr[i].count)
			arr[i] = (ND) { arr[i / 2].count + 1, i / 2 };
		if (arr[i - 1].count + 1 < arr[i].count)
			arr[i] = (ND) { arr[i - 1].count + 1, i - 1 };
	}
	return;
}

int main() {
	init();
	int a;
	scanf("%d", &a);
	printf("%d\n", arr[a].count);
	for (; a != END; a = arr[a].pre)
		printf("%d ", a);
	return 0;
}