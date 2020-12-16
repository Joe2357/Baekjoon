#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;
typedef struct RGB {
	int r_r, r_g, r_b;
	int g_r, g_g, g_b;
	int b_r, b_g, b_b;
} RGB;

int main() {
	// i/o init
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	// init
	int n;
	cin >> n;
	vector<RGB> arr(n + 1);

	// dp init
	int a, b, c;
	cin >> a >> b >> c;
	arr[1] = { a, INF, INF, INF, b, INF, INF, INF, c };

	// dp algorithm
	for (int i = 2; i <= n; i++) {
		// input
		int r, g, b;
		cin >> r >> g >> b;

		// red start
		arr[i].r_r = min(arr[i - 1].r_g, arr[i - 1].r_b), arr[i].r_r += r;
		arr[i].r_g = min(arr[i - 1].r_r, arr[i - 1].r_b), arr[i].r_g += g;
		arr[i].r_b = min(arr[i - 1].r_r, arr[i - 1].r_g), arr[i].r_b += b;

		// green start
		arr[i].g_r = min(arr[i - 1].g_g, arr[i - 1].g_b), arr[i].g_r += r;
		arr[i].g_g = min(arr[i - 1].g_r, arr[i - 1].g_b), arr[i].g_g += g;
		arr[i].g_b = min(arr[i - 1].g_r, arr[i - 1].g_g), arr[i].g_b += b;

		// blue start
		arr[i].b_r = min(arr[i - 1].b_g, arr[i - 1].b_b), arr[i].b_r += r;
		arr[i].b_g = min(arr[i - 1].b_r, arr[i - 1].b_b), arr[i].b_g += g;
		arr[i].b_b = min(arr[i - 1].b_r, arr[i - 1].b_g), arr[i].b_b += b;
	}

	// get result
	int retval = min(arr[n].r_g, arr[n].r_b);
	retval = min(retval, arr[n].g_r),
		retval = min(retval, arr[n].g_b),
		retval = min(retval, arr[n].b_r),
		retval = min(retval, arr[n].b_g);

	cout << retval;
	return 0;
}