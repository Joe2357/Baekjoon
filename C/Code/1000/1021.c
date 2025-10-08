#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 50
bool removed[MAX_IDX];
int n;

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	scanf("%d", &n);

	int m;
	scanf("%d", &m);

	int retval = 0;
	int cur = 0;
	while (m--) {
		int a;
		scanf("%d", &a);

		// left
		int leftCur = cur;
		int leftRetval = 0;
		while (leftCur != (a - 1)) {
			if (++leftCur == n) {
				leftCur -= n;
			}
			if (removed[leftCur] == false) {
				++leftRetval;
			}
		}

		// right
		int rightCur = cur;
		int rightRetval = 0;
		while (rightCur != (a - 1)) {
			if (--rightCur < 0) {
				rightCur += n;
			}
			if (removed[rightCur] == false) {
				++rightRetval;
			}
		}

		removed[a - 1] = true;
		retval += min(leftRetval, rightRetval);

		cur = a % n;
		for (int i = 0; i < n; ++i) {
			if (removed[cur] == false) {
				break;
			}
			if (++cur == n) {
				cur -= n;
			}
		}
	}

	printf("%d", retval);
	return 0;
}