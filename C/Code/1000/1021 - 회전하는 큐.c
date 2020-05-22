#include <stdio.h>
#define min(a, b) (a > b) ? b : a					// macro function

int arr[50], result, rear;							// queue

int main(n, m) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)						// initialize
		arr[i] = i + 1;
	for (; m && n > 1; m--) {						// loop while pop every value
		int search, temp = 0;
		scanf("%d", &search);						// searching value
		while (arr[(rear + temp) % n] != search)	// move count ( right )
			temp++;
		result += min(temp, n - temp);				// left and right, which is min?
		rear = (rear + temp) % n;					// modulo n = repeat using of queue
		for (int i = rear; i < n; i++)				// erase empty space
			arr[i] = arr[i + 1];
		rear %= --n;
	}
	printf("%d", result);
	return 0;
}