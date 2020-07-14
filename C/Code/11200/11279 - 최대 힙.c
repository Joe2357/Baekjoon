#include <stdio.h>

long long max_arr[100002];
int max_rear;

long long max_pop() {
	if (!max_rear) // empty
		return 0;
	else {
		long long r = max_arr[1];
		int i = 1, tp = 2;
		max_arr[1] = max_arr[max_rear], max_arr[max_rear--] = 0;
		while (tp < max_rear) { // move down
			tp += (max_arr[tp] < max_arr[tp + 1]);
			if (max_arr[i] >= max_arr[tp])
				break;
			long long b = max_arr[i];
			max_arr[i] = max_arr[tp], max_arr[tp] = b;
			i = tp, tp = 2 * i;
		}
		if (tp == max_rear && max_arr[i] < max_arr[tp]) { // only have left child
			long long b = max_arr[i];
			max_arr[i] = max_arr[tp], max_arr[tp] = b;
		}
		return r;
	}
}

void max_push(long long a) {
	max_arr[++max_rear] = a;
	int i = max_rear;
	while (i != 1 && a > max_arr[i / 2]) { // move up
		long long b = max_arr[i / 2];
		max_arr[i / 2] = a, max_arr[i] = b, i /= 2;
	}
}

int main(t) {
	for (scanf("%d", &t); t; t--) {
		long long temp;
		scanf("%lld", &temp);
		if (!temp)
			printf("%lld\n", max_pop());
		else
			max_push(temp);
	}
	return 0;
}