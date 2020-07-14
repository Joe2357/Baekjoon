#include <stdio.h>
#include <string.h>

int main(t, n) {
	for (scanf("%d", &t); t; t--) {
		int countarr[30] = { 0 }, result = 1;
		char strarr[30][21] = { 0 }, strtemp[21]; // didn't use hash..

		for (scanf("%d", &n); n; n--) {
			scanf("%s %s", strtemp, strtemp); // only using second string
			int i = 0;
			while (strarr[i]) { // find correct place
				if (!strcmp(strarr[i], strtemp) || !strarr[i][0])
					break;
				i++;
			}
			strcpy(strarr[i], strtemp); // place string to correct place
			countarr[i]++;
		}
		for (int i = 0; i < 30; i++) // counting
			result *= (countarr[i] + 1);
		printf("%d\n", result - 1); // remove 1 ( didn't select anything )
	}
	return 0;
}