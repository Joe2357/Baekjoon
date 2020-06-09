#include <stdio.h>

int main() {
	int n, temp = 666, count = 0;				// temp = first target number
	for(scanf("%d", &n); count != n; temp++) {	// brute force ( end if we fount 'n'th target number
		int temp2 = temp;
		while (temp2) {
			if (temp2 % 1000 == 666) {			// if target has "666"
				count++;						// count + 1
				break;
			}
			temp2 /= 10;
		}
	}
	printf("%d", --temp);						// while escaping for statement, temp will be ++, so we have to remove 1
	return 0;
}