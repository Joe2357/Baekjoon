#include <stdio.h>

int main(t1) {
	// test case
	for (scanf("%d", &t1); t1; t1--) {
		int a = 0, b = 0, t2;

		// rock-scissors-paper
		for (scanf("%d", &t2); t2; t2--) {
			char temp1, temp2;
			scanf(" %c %c", &temp1, &temp2);

			// player 2 win
			if (temp1 == 'R' && temp2 == 'P' ||
				temp1 == 'P' && temp2 == 'S' ||
				temp1 == 'S' && temp2 == 'R')
				b++;

			// player 1 win
			else if (temp1 == 'R' && temp2 == 'S' ||
				temp1 == 'S' && temp2 == 'P' ||
				temp1 == 'P' && temp2 == 'R')
				a++;
		}
		if (a > b)
			printf("Player 1\n");
		else if (a < b)
			printf("Player 2\n");
		else
			printf("TIE\n");
	}
	return 0;
}