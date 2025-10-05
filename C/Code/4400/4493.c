#include <stdio.h>

int main(t1) {
	for (scanf("%d", &t1); t1; t1--) {
		int a = 0, b = 0, t2;
		for (scanf("%d", &t2); t2; t2--) {
			char temp1, temp2;
			scanf(" %c %c", &temp1, &temp2);
			b += (temp1 == 'R' && temp2 == 'P' ||
				  temp1 == 'P' && temp2 == 'S' ||
				  temp1 == 'S' && temp2 == 'R');
			a += (temp1 == 'R' && temp2 == 'S' ||
				  temp1 == 'S' && temp2 == 'P' ||
				  temp1 == 'P' && temp2 == 'R');
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