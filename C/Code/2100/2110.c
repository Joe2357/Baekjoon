#include <stdio.h>
#define MAX_INDEX 200000

int arr[MAX_INDEX], n, c;

int cmp(int *a, int *b)
{
	return *a - *b;
}

int getTemp(int dist)
{
	int setDevice = 1,
		currentDistance = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] - currentDistance >= dist)
			setDevice++, currentDistance = arr[i];
	return (setDevice >= c);
}

int main()
{
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), cmp);
	int start = 0, end = arr[n - 1];
	while (start + 1 < end)
	{
		int mid = (start + end) / 2;
		int tempR = getTemp(mid);
		if (tempR)
			start = mid;
		else
			end = mid - 1;
	}
	end -= !(getTemp(end));
	printf("%d", end);
	return 0;
}