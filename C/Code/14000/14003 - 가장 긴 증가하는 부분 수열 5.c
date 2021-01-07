#include <stdio.h>

typedef struct Node
{
	int value;
	int index;
} ND;

#define M_I 1000000
ND arr[M_I];
int lis[M_I];
int len;
int n;

int lowerbound(int x)
{
	int start = 0, end = len - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (lis[mid] == x)
			return mid;
		else if (lis[mid] > x)
			end = mid - 1;
		else
			start = mid;
	}
	return end;
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &arr[0].value);
	arr[0].index = len = 1;
	lis[0] = arr[0].value;
	for (int i = 1; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		arr[i].value = a;
		if (lis[len - 1] < a)
		{
			lis[len++] = a;
			arr[i].index = len;
		}
		else
		{
			lis[arr[i].index = lowerbound(a)] = a;
		}
	}

	printf("%d\n", len);
	for (--n; n; --n)
	{
		if (arr[n].index == len)
			break;
	}
	for (int a = len; a; --n)
	{
		if (arr[n].index == a)
		{
			lis[--a] = arr[n].value;
		}
	}
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", lis[i]);
	}

	return 0;
}