#include <stdio.h>

int main() {
	// ex();
	char tl[12] = "FFFFFFDCBAA";
	int n;
	scanf("%d", &n);
	printf("%c", tl[n / 10]); // string indexing
	return 0;
}

void ex() {
	int n;
	scanf("%d", &n);
	if (n >= 90 && n <= 100)
		printf("A");
	else if (n >= 80 && n <= 89)
		printf("B");
	else if (n >= 70 && n <= 79)
		printf("C");
	else if (n >= 60 && n <= 69)
		printf("D");
	else
		printf("F");
	return 0;
}