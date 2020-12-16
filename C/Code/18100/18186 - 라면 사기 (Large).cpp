#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct Noodle {
	long long b, c, d;
	long long count;
} ND;

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	int n, b, c;
	long long result = 0, sum = 0;
	vector<ND> noodle;
	cin >> n >> b >> c;

	noodle.push_back({ 0 }); // -2 company
	noodle.push_back({ 0 }); // -1 company
	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		noodle.push_back({ 0, 0, 0, temp });
		sum += temp;
	}
	noodle.push_back({ 0 }); // n+1 company
	noodle.push_back({ 0 }); // n+2 company

	if (b <= c) { // don't need to start algorithm
		cout << sum * b;
		return 0;
	}

	// get result
	for (int i = 2; i < n + 2; i++) { // from the first company to end

		// make 2 noodles in one set
		long long temp = min(noodle[i - 1].b, noodle[i].count);
		result += (temp * c);
		noodle[i - 1].b -= temp, noodle[i].count -= temp, noodle[i].c += temp;

		// make 3 noodles in one set
		temp = min(noodle[i - 1].c, noodle[i].count);
		result += (temp * c);
		noodle[i - 1].c -= temp, noodle[i].count -= temp, noodle[i].d += temp;

		// make remained noodles to one set ( 1 noodle per a set )
		result += (noodle[i].count * b);
		noodle[i].b = noodle[i].count, noodle[i].count = 0;
	}

	// print result
	cout << result;
	return 0;
}