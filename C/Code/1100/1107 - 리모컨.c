#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define M (int)(1e6 + 1)
const int start = 100;

bool broken[11];
int target;
int result;

/*
  func : canUse(int)
  description : return whether input number can be used
  return :
	= true ( when every button was not broken )
	= false ( when at least 1 button was broken )
*/
bool canUse(int x) {
	if (x == 0) {
		return !broken[0];
	}
	bool c = true;
	while (x > 0) {
		c &= (!broken[x % 10]);
		x /= 10;
	}
	return c;
}

/*
  func : press(int)
  description : return the length of number
  return :
	= (int)len ( the length of input number )
*/
int press(int x) {
	if (x == 0) {
		return 1;
	}

	int p = 0;
	while (x > 0) {
		++p;
		x /= 10;
	}
	return p;
}

#define abs(x) (((x) < 0) ? (-(x)) : (x))	 // abstract function
#define min(a, b) (((a) > (b)) ? (b) : (a))	 // return smaller value
int main() {
	int n;
	scanf("%d %d", &target, &n);
	while (n--) {
		int x;
		scanf("%d", &x);
		broken[x] = true;
	}

	result = abs(target - start);  // start = 100
	for (int i = 0; i < M; ++i) {  // brute force
		if (canUse(i)) {
			result = min(result, abs(i - target) + press(i));
			if (i >= target) {	// no need to search above
				break;
			}
		}
	}

	printf("%d", result);
	return 0;
}