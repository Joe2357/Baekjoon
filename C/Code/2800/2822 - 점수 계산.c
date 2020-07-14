#include <stdio.h>

typedef struct Problem {
	int point, num;
} PB;

int compare1(PB *a, PB *b) {
	return b->point - a->point;
}
int compare2(PB *a, PB *b) {
	return a->num - b->num;
}

int main() {
	PB arr[10];
	for (int i = 0; i < 8; i++) {
		int temp;
		scanf("%d", &temp);
		arr[i].point = temp,
			arr[i].num = i + 1;
	}
	qsort(arr, 8, sizeof(arr[0]), compare1);    // point descending order
	qsort(arr, 5, sizeof(arr[0]), compare2);    // number ascending order
	int result = 0;
	for (int i = 0; i < 5; i++)                 // sum of 5 questions
		result += arr[i].point;
	printf("%d\n", result);
	for (int i = 0; i < 5; i++)                 // print question numbers
		printf("%d ", arr[i].num);
	return 0;
}