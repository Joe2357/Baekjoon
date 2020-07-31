#include <stdio.h>
#define True 1
#define False 0

typedef char boolean;

char result[101];
int length;
boolean isMade;

void makeString(int *arr, int max) {
	int used = 0;
	boolean isNotIdx;
	for (int i = 1; i <= length; i++) { // from start of string to end of string
		isNotIdx = True;
		for (int j = 0; j < max; j++)
			if (arr[j] == i) { // if that position must have certain alphabet
				result[i - 1] = j + 'A', arr[j]--, used += (arr[j] == 0); // give that alphabet
				isNotIdx = False;
				break;
			}
		if (isNotIdx) // or not, select correct alphabet greedy
			result[i - 1] = used + 'A', arr[used]--, used += (arr[used] == 0);
	}

	return;
}

// backtrack function
void bt(int *arr, int index, int used, int willuse) {
	if (isMade)
		// string already made
		return;
	else if (index + willuse == length) { // can make string
		isMade = True;
		makeString(arr, used);
		return;
	}
	else if (index + willuse > length) // out of range
		return;
	else { // need more search
		for (int i = index + willuse + 1; i > index; i--) {
			// backtrack recursion search
			arr[used] = i;
			bt(arr, i, used + 1, willuse + index);
			arr[used] = 0;
		}
	}
	return;
}

int main() {
	// init
	int alpha[26] = { 0 };
	scanf("%d", &length);

	// backtrack
	bt(alpha, 0, 0, 0);

	// print result
	if (isMade)
		printf("%s", result);
	else
		printf("-1");

	return 0;
}