#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;

#define MAX_COLOR 10
#define MAX_LEN 6
const int INPUT_COLOR_CNT = 3;

char color[MAX_COLOR][MAX_LEN + 1] = {
	"black", "brown", "red", "orange", "yellow",
	"green", "blue", "violet", "grey", "white"};

ll get_color_index(char* str) {
	for (int i = 0; i < MAX_COLOR; ++i) {
		bool isMatched = true;

		for (int j = 0; str[j] != '\0'; ++j) {
			if (str[j] != color[i][j]) {
				isMatched = false;
				break;
			}
		}

		if (isMatched == true) {
			return i;
		}
	}
}

ll power(ll a, ll b) {
	ll ret = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ret *= a;
		}
		a *= a;
		b /= 2;
	}
	return ret;
}

int main() {
	ll result = 0;
	char input[MAX_LEN + 1];
	ll color_idx;

	// 첫번째 색깔
	scanf("%s", input);
	color_idx = get_color_index(input);
	result += (color_idx * 10);

	// 두번째 색깔
	scanf("%s", input);
	color_idx = get_color_index(input);
	result += color_idx;

	// 세번째 색깔
	scanf("%s", input);
	color_idx = get_color_index(input);
	result *= power(10, color_idx);

	printf("%lld", result);
	return 0;
}