#include <stdio.h>

typedef struct Node {
	int max_value, min_value;
} Node;

#define MAX_CASE 3
const int LEFT = 0;
const int MID = 1;
const int RIGHT = 2;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	Node ret[MAX_CASE];
	int n;
	scanf("%d", &n);

	ret[LEFT] = (Node){0, 0}, ret[MID] = (Node){0, 0}, ret[RIGHT] = (Node){0, 0};

	Node temp[MAX_CASE];
	while (n--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		temp[LEFT] = (Node){
			max(ret[LEFT].max_value, ret[MID].max_value) + a,
			min(ret[LEFT].min_value, ret[MID].min_value) + a};
		temp[MID] = (Node){
			max(max(ret[LEFT].max_value, ret[MID].max_value), ret[RIGHT].max_value) + b,
			min(min(ret[LEFT].min_value, ret[MID].min_value), ret[RIGHT].min_value) + b};
		temp[RIGHT] = (Node){
			max(ret[MID].max_value, ret[RIGHT].max_value) + c,
			min(ret[MID].min_value, ret[RIGHT].min_value) + c};

		ret[LEFT] = temp[LEFT], ret[MID] = temp[MID], ret[RIGHT] = temp[RIGHT];
	}

	printf("%d %d", max(max(ret[LEFT].max_value, ret[MID].max_value), ret[RIGHT].max_value),
		   min(min(ret[LEFT].min_value, ret[MID].min_value), ret[RIGHT].min_value));
	return 0;
}