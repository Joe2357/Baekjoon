#include <stdio.h>
#define MAX_INDEX 50010

int minQ[MAX_INDEX], minR; // min heap ( more than middle )
int maxQ[MAX_INDEX], maxR; // max heap ( less than middle )
int result;

// max heap pop function
int max_pop() {
	if (!maxR)
		return 0;
	else {
		int r = maxQ[1];
		int i = 1, tp = 2;
		maxQ[1] = maxQ[maxR], maxQ[maxR--] = 0;
		while (tp < maxR) {
			tp += (maxQ[tp] < maxQ[tp + 1]);
			if (maxQ[i] >= maxQ[tp])
				break;
			int b = maxQ[i];
			maxQ[i] = maxQ[tp], maxQ[tp] = b;
			i = tp, tp = 2 * i;
		}
		if (tp == maxR && maxQ[i] < maxQ[tp]) {
			int b = maxQ[i];
			maxQ[i] = maxQ[tp], maxQ[tp] = b;
		}
		return r;
	}
}

// max heap push function
void max_push(int a) {
	maxQ[++maxR] = a;
	int i = maxR;
	while (i != 1 && a > maxQ[i / 2]) {
		int b = maxQ[i / 2];
		maxQ[i / 2] = a, maxQ[i] = b, i /= 2;
	}
}

// min heap pop function
int min_pop() {
	if (!minR)
		return 0;
	else {
		int r = minQ[1];
		int i = 1, tp = 2;
		minQ[1] = minQ[minR], minQ[minR--] = 0;
		while (tp < minR) {
			tp += (minQ[tp] > minQ[tp + 1]);
			if (minQ[i] <= minQ[tp])
				break;
			int b = minQ[i];
			minQ[i] = minQ[tp], minQ[tp] = b;
			i = tp, tp = 2 * i;
		}
		if (tp == minR && minQ[i] > minQ[tp]) {
			int b = minQ[i];
			minQ[i] = minQ[tp], minQ[tp] = b;
		}
		return r;
	}
}

// min heap push function
void min_push(int a) {
	minQ[++minR] = a;
	int i = minR;
	while (i != 1 && a < minQ[i / 2]) {
		int b = minQ[i / 2];
		minQ[i / 2] = a, minQ[i] = b, i /= 2;
	}
}

int main(t) {
	// first value
	scanf("%d", &t);
	scanf("%d", &result);
	printf("%d\n", result);

	// after the next value
	for (t--; t; t--) {
		int temp;
		scanf("%d", &temp);

		// push step
		if (temp == result) { // equals with middle
			if (minR < maxR)
				// less > more
				min_push(temp);
			else
				// less <= more
				max_push(temp);
		}
		else if (temp < result) { // less than middle
			min_push(result);
			max_push(temp);
			result = max_pop();
		}
		else if (temp > result) { // more then middle
			max_push(result);
			min_push(temp);
			result = min_pop();
		}

		// setting step
		while (minR > maxR + 1) { // too many 'more' value
			max_push(result);
			result = min_pop();
		}
		while (minR + 1 < maxR) { // too many 'less' value
			min_push(result);
			result = max_pop();
		}

		// print result step
		if (minR < maxR)
			printf("%d\n", maxQ[1]);
		else
			printf("%d\n", result);
	}
	return 0;
}