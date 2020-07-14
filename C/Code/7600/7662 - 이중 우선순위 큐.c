#include <stdio.h>
#define MAX_INDEX 1000001

long min_arr[MAX_INDEX], max_arr[MAX_INDEX];
int max_rear, min_rear;

void swap(long *a, long *b) {
	long c = *a;
	*a = *b, *b = c;
	return;
}

long max_pop() {
	long r = max_arr[1];
	int i = 1, tp = 2;
	max_arr[1] = max_arr[max_rear], max_arr[max_rear--] = 0;
	while (tp < max_rear) {
		tp += (max_arr[tp] < max_arr[tp + 1]);
		if (max_arr[i] >= max_arr[tp])
			break;
		swap(&max_arr[i], &max_arr[tp]);
		i = tp, tp = 2 * i;
	}
	if (tp == max_rear && max_arr[i] < max_arr[tp])
		swap(&max_arr[i], &max_arr[tp]);
	return r;
}

long min_pop() {
	long r = min_arr[1];
	int i = 1, tp = 2;
	min_arr[1] = min_arr[min_rear], min_arr[min_rear--] = 0;
	while (tp < min_rear) {
		tp += (min_arr[tp] > min_arr[tp + 1]);
		if (min_arr[i] <= min_arr[tp])
			break;
		swap(&min_arr[i], &min_arr[tp]);
		i = tp, tp = 2 * i;
	}
	if (tp == min_rear && min_arr[i] > min_arr[tp])
		swap(&min_arr[i], &min_arr[tp]);
	return r;
}

void max_push(long a, int index) {
	max_arr[index] = a;
	int i = index;
	while (i != 1 && a > max_arr[i / 2]) {
		swap(&max_arr[i / 2], &max_arr[i]);
		i /= 2;
	}
}

void min_push(long a, int index) {
	min_arr[index] = a;
	int i = index;
	while (i != 1 && a < min_arr[i / 2]) {
		swap(&min_arr[i / 2], &min_arr[i]);
		i /= 2;
	}
}

int main(t1, t2) {
	// test case
	for (scanf("%d", &t1); t1; t1--) {
		// init
		while (min_rear)
			min_pop();
		while (max_rear)
			max_pop();

		// command
		for (scanf("%d", &t2); t2; t2--) {
			char str[3];
			long temp;
			scanf("%s %ld", str, &temp);

			// push all heaps
			if (str[0] == 'I') {
				max_push(temp, ++max_rear);
				min_push(temp, ++min_rear);
			}
			else {
				// pop
				if (temp == 1) {
					if (!max_rear)
						continue; // can't pop
					long tempValue = max_pop(); // pop from max

					// delete from min
					int i = min_rear;
					for (; min_arr[i] != tempValue; i--)
						;
					min_push(min_arr[min_rear], i);
					min_arr[min_rear--] = 0;
				}
				else {
					if (!min_rear)
						continue;
					long tempValue = min_pop();
					int i = max_rear;
					for (; max_arr[i] != tempValue; i--)
						;
					max_push(max_arr[max_rear], i);
					max_arr[max_rear--] = 0;
				}
			}
		}

		// print result
		if (!min_rear && !max_rear)
			printf("EMPTY\n");
		else
			printf("%ld %ld\n", max_arr[1], min_arr[1]);
	}
	return 0;
}