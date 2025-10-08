#include <stdio.h>
#define MAX 9999
#define min(a, b) (((a) < (b)) ? (a) : (b))

int arr[20][20], n, minValue = MAX;

int evil(int* man) {
	int result[3] = {0};
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (man[i] == man[j])
				result[man[i]] += arr[i][j] + arr[j][i];
	result[2] = result[0] - result[1];
	if (result[2] < 0)
		result[2] *= -1;
	return result[2];
}

void back(int* man, int t, int a) {
	if (t == n / 2) {
		minValue = min(minValue, evil(man));
		return;
	} else if (a == n)
		return;
	int tempMan[20];
	for (int i = 0; i < 20; i++)
		tempMan[i] = man[i];
	tempMan[a] = 1;
	back(tempMan, t + 1, a + 1);
	tempMan[a] = 0;
	back(tempMan, t, a + 1);
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n * n; i++)
		scanf("%d", &arr[i / n][i % n]);
	int man[20] = {0};
	back(man, 0, 0);
	printf("%d", minValue);
	return 0;
}