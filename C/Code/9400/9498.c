#include <stdio.h>

#define MAX_IDX 10

char grade_table[MAX_IDX + 1] = {'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A', 'A'};

int main() {
	int n;
	scanf("%d", &n);
	printf("%c", grade_table[n / 10]);
	return 0;
}