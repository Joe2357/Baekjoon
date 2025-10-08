#include <stdio.h>

int min_arr[100002];
int min_rear;

int min_pop() {
	if (!min_rear)
		return 0;
	else {
		int retval = min_arr[1];
		min_arr[1] = min_arr[min_rear--];

		int a = 1, b = 2;
		while (b <= min_rear) {
			b += ((b != min_rear) & (min_arr[b] > min_arr[b + 1]));
			if (min_arr[a] <= min_arr[b]) {
				break;
			} else {
				int c = min_arr[a];
				min_arr[a] = min_arr[b];
				min_arr[b] = c;
			}
			a = b, b <<= 1;
		}

		return retval;
	}
}

void push(int x) {
	min_arr[++min_rear] = x;
	for (int t = min_rear; t > 1 && x < min_arr[t >> 1]; t >>= 1) {
		int a = min_arr[t >> 1];
		min_arr[t >> 1] = x, min_arr[t] = a;
	}
	return;
}

int main(tc) {
	for (scanf("%d", &tc); tc; tc--) {
		int temp;
		scanf("%d", &temp);
		if (!temp)
			printf("%d\n", min_pop());
		else
			push(temp);
	}
	return 0;
}