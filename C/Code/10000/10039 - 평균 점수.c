#include <stdio.h>

int main() {
	int score = 0;
	for (int i = 0; i < 5; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp < 40) // minimum score = 40
			temp = 40;
		score += temp;
	}
	printf("%d", score / 5);
	return 0;
}