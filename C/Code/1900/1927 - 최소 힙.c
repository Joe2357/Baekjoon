#include <stdio.h>

int arr[100002], rear;		// heap, rear

int pop() {
	if (!rear)		// isEmpty
		return 0;
	else {
		int result = arr[1], i = 1, tp = 2;		// first value is minimum value
		arr[1] = arr[rear], arr[rear--] = 0;	// move last value to root
		while (tp < rear) {						// downgrading
			tp += (arr[tp] > arr[tp + 1]);
			if (arr[i] < arr[tp])
				break;
			int b = arr[i];
			arr[i] = arr[tp], arr[tp] = b;
			i = tp, tp = 2 * i;
		}
		if (tp == rear && arr[i] > arr[tp]) {	// only has left child
			int b = arr[i];
			arr[i] = arr[tp], arr[tp] = b;
		}
		return result;							// return minimum value
	}
}

void push(int a) {
	arr[++rear] = a;							// pushing
	int i = rear;
	while (i != 1 && a < arr[i / 2]) {			// upgrading
		int b = arr[i / 2];
		arr[i / 2] = a, arr[i] = b, i /= 2;
	}
}

int main(t, n) {
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &n);
		if (!n)
			printf("%d\n", pop());
		else
			push(n);
	}
	return 0;
}