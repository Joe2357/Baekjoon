#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int count[8001] = {0}, max, min, cnt = 0, temp;
	long long avgtemp = 0;
	double avg1 = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (!i)
			max = temp, min = temp;
		else {
			if (temp > max)
				max = temp;
			if (temp < min)
				min = temp;
		}
		count[temp + 4000]++, avg1 += temp;
		if (count[temp + 4000] > cnt)
			cnt = count[temp + 4000];
	}
	avg1 = avg1 / n * 1.0;
	while (avg1 >= 1)
		avg1--, avgtemp++;
	while (avg1 < 0)
		avg1++, avgtemp--;
	if (avg1 >= 0.5)
		avgtemp++;
	printf("%lld\n", avgtemp);
	temp = n / 2;
	for (int i = 0; i < 8001; i++) {
		temp -= count[i];
		if (temp < 0) {
			printf("%d\n", i - 4000);
			break;
		}
	}
	temp = -1;
	for (int i = 0; i < 8001; i++) {
		if (count[i] == cnt) {
			if (temp == -1)
				temp = i;
			else {
				printf("%d\n", i - 4000);
				temp = -1;
				break;
			}
		}
	}
	if (temp != -1)
		printf("%d\n", temp - 4000);
	printf("%d", max - min);
	return 0;
}