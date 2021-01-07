#include <iostream>

using namespace std;

int main() {
	int n;
	int a;
	int b[500];
	cin >> n >> a;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int k = 0, t = 0;
	for (int i = 0; i < n; i++) {
		t += b[i];
		if (t > a) {
			break;
		}
		k++;
	}
	cout << k;
}