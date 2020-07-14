#include <stdio.h>

int main(d, m) {
	char str[7][10] = {
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday",
		"Monday",
		"Tuesday",
	};
	int arr[13] = {
		0, 0, 31, 28, 31,
		30, 31, 30, 31, 31,
		30, 31, 30 };
	for (scanf("%d %d", &d, &m); m; m--)
		d += arr[m];    // day calc
	printf("%s", str[d % 7]);   // 1 = Thursday
	return 0;
}