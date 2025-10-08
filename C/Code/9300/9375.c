#include <stdio.h>
#include <string.h>

int main(t, n) {
	for (scanf("%d", &t); t; t--) {
		int countarr[30] = {0}, result = 1;
		char strarr[30][21] = {0}, strtemp[21];
		for (scanf("%d", &n); n; n--) {
			scanf("%s %s", strtemp, strtemp);
			int i = 0;
			while (strarr[i]) {
				if (!strcmp(strarr[i], strtemp) || !strarr[i][0])
					break;
				i++;
			}
			strcpy(strarr[i], strtemp);
			countarr[i]++;
		}
		for (int i = 0; i < 30; i++)
			result *= (countarr[i] + 1);
		printf("%d\n", result - 1);
	}
	return 0;
}