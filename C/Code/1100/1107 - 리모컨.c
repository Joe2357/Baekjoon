#include <stdio.h>

int main() {
	int ban[10] = { 0 }, n, temp;
	scanf("%d", &n);
	scanf("%d", &temp);
	for (int i = 0; i < temp; i++) {
		int temp2;
		scanf("%d", &temp2);
		ban[temp2] = 1;							// banned button = True
	}
	int min = -1;
	for (int i = 0; i < 10000000; i++) {		// we have to search until temp < 9999999
		temp = i;
		int count = 0, boolean = 0;
		if (!temp)								// temp = 0
			if (!ban[0])						// '0' didn't banned
				count = 1;
			else
				continue;
		while (temp) {
			if (ban[temp % 10]) {
				boolean = 1;					// can't make temp without banned button
				break;
			}
			count++;
			temp /= 10;
		}
		if (boolean)
			continue;
		temp = n - i;							// how many times we have to ++ or --
		if (temp < 0)
			temp *= -1;
		count += temp;
		if (( min == -1 ) || ( min > count ))	// update minimum
			min = count;
		if (i > n)								// checked last temp
			break;
	}
	temp = 100 - n;								// starting point = 100
	if (temp < 0)
		temp *= -1;
	if ((min > temp)||(min == -1))
		min = temp;
	printf("%d", min);
	return 0;
}