#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#define MAX_INDEX 100000

using namespace std;

typedef struct Position {
	int x, y;
	Position() {
	}
	Position(int a, int b) : x(a), y(b) {
	}
	bool operator<(const Position &v) const {
		if (y == v.y)
			return x < v.x;
		else
			return y < v.y;
	}
} PS;

PS arr[MAX_INDEX];
int result = 800000000;

bool compareX(PS a, PS b) {
	return a.x < b.x;
}

int dist(PS a, PS b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	// initialize
	int n;
	scanf("%d", &n);
	vector<PS> arr(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);
	sort(arr.begin(), arr.end(), compareX);
	result = dist(arr[0], arr[1]);
	int start = 0; // time saving ( don't need to compare from first )

	// sweep-line algorithm
	// not using vector?
	set<PS> tempSet = { arr[0], arr[1] }; // initial
	for (int i = 2; i < n; i++) {
		PS current = arr[i]; // current using
		while (start < i) {	 // don't need to compare from first
			auto use = arr[start];
			if ((current.x - use.x) * (current.x - use.x) > result) {
				tempSet.erase(use);
				start++;
			}
			else
				break;
		}
		int bound_d = (int)sqrt((double)result) + 1;
		// the biggest rectangle
		auto lowestPoint = PS(-100000, current.y - bound_d);
		auto mostPoint = PS(100000, current.y + bound_d);
		// nowY - result ~ nowY + result // binary search
		auto lower = tempSet.lower_bound(lowestPoint);
		auto upper = tempSet.upper_bound(mostPoint);

		// get result
		for (auto it = lower; it != upper; it++)
			result = min(result, dist(current, *it));

		tempSet.insert(current); // insert current
	}
	printf("%d", result);
	return 0;
}