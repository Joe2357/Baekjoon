#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	int n, k;
	cin >> n >> k;

	// get modulo & length
	long long mod = n % k, length = 1;
	while (n / length >= 10)
		length *= 10;
	length *= 10;

	// get result
	int i;
	long long temp = mod;
	for (i = 0; i < k && temp > 0; i++) {
		temp *= length, temp += mod;
		temp %= k;
	}

	// print result
	if (i == k)
		cout << -1;
	else
		cout << i + 1;

	return 0;
}