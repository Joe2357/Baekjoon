#include <stdio.h>

int main() {
	int as = 1, des = 1;
	for (int i = 0; i < 8; i++) {
		int temp;
		scanf("%d", &temp);
		as *= (temp == i + 1),      // if not ascending, as = 0
			des *= (temp == 8 - i); // if not desending, des = 0
	}
	if (as)
		printf("ascending");
	else if (des)                   // can't also true is as si true
		printf("descending");
	else
		printf("mixed");
	return 0;
}