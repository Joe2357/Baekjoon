#include <stdio.h>
#define MAX_INDEX 81
#define True 1
#define False 0

typedef char boolean;

int n;
char str[MAX_INDEX];
boolean created = False;

// check whether making string is "nice string"
boolean isValid(int now) {
	// from 0 to half of string
	for (int length = (now + 1) / 2; length; length--) {
		// init
		boolean temp = True;
		int start = now - length;

		// string compare
		for (int i = 0; i < length; i++)
			if (str[start - i] != str[now - i]) {
				temp = False;
				break;
			}

		// if temp = true, it has common substring
		if (temp)
			return False;
	}
	// no matches
	return True;
}

void back(int now) {
	if (created) // return all stacked call
		return;
	else if (now >= n) { // created string ( result found )
		created = True;
		return;
	}
	else { // more have to run
		str[now] = '1';
		if (isValid(now))
			back(now + 1);
		if (created)
			return;
		str[now] = '2';
		if (isValid(now))
			back(now + 1);
		if (created)
			return;
		str[now] = '3';
		if (isValid(now))
			back(now + 1);
	}
}

int main() {
	// init
	scanf("%d", &n);

	// backtracking
	back(0);

	// print result
	printf("%s", str);
	return 0;
}