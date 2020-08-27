#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_INDEX 50
#define MAX_NUMBER 15

using namespace std;

typedef struct Number
{
	int value;
	int length;
} NM;

vector<NM> arr;
int dp[65535][100];
char str[MAX_NUMBER][MAX_INDEX + 1];
int moduler[MAX_INDEX + 1];
int n, k;

long long gcd(long long a, long long b)
{
	while (b != 0)
	{
		long long c = a;
		a %= b, b = c;
	}
	return a;
}

int main()
{
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
		arr.push_back({0, strlen(str[i])});
	}
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		for (int j = 0; str[i][j]; j++)
			a *= 10, a += (str[i][j] - '0'), a %= k;
		arr[i].value = a;
	}
	int a = 1;
	for (int i = 1; i <= MAX_INDEX; i++)
		a *= 10, a %= k, moduler[i] = a;

	// get factorial
	long long ret1 = 0, ret2 = 1;
	for (int i = 2; i <= n; i++)
		ret2 *= i;

	return 0;
}