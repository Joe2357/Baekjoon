#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	char str[2][51];
	scanf("%s", str[0]);							// standard string
	for (n--; n; n--) {
		scanf("%s", str[1]);						// temp string
		int temp = 0;
		while (str[1][temp]) {						// comparing
			if (str[1][temp] != str[0][temp])		// something differet?
				str[0][temp] = '?';					// standard string => ?
			temp++;
		}
	}
	printf("%s", str[0]);							// printing standard
	return 0;
}