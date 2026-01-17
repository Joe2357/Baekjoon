#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX_IDX = (int)(2e9);

int main() {
	srand((unsigned int)time(NULL));
	printf("%d", rand() % MAX_IDX);
}