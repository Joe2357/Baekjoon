#include <stdio.h>
#include <stdlib.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef long long ll;

#define MAX_IDX (int)(1e5)

typedef struct Line {
	ll s, e;
} Line;

Line line[MAX_IDX];
int n, d;

ll min_heap[MAX_IDX + 10 + 1];
int heap_size = 0;

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		line[i] = (Line){min(a, b), max(a, b)};
	}
	scanf("%d", &d);
	return;
}

int end_asc(const void* a, const void* b) {
	Line* x = (Line*)a;
	Line* y = (Line*)b;

	if (x->e > y->e) {
		return 1;
	} else if (x->e < y->e) {
		return -1;
	} else {
		return 0;
	}
}

void init() {
	int l = 0;
	for (int i = 0; i < n; ++i) {
		if (line[i].e - line[i].s <= d) { // 애초에 길이가 d인 선분으로 덮을 수 없는 경우는 제외
			line[l++] = line[i];
		}
	}
	n = l;
	qsort(line, n, sizeof(Line), end_asc); // 도착점 기준 정렬
	return;
}

int getHeapLength() {
	return heap_size;
}

void insert(ll x) {
	min_heap[++heap_size] = x;

	int idx = heap_size;
	while (idx > 1 && min_heap[idx] < min_heap[idx / 2]) {
		min_heap[idx] = min_heap[idx / 2], min_heap[idx / 2] = x;
		idx /= 2;
	}
	return;
}

ll pop() {
	ll min_val = min_heap[1];
	min_heap[1] = min_heap[heap_size--];

	int idx = 1;
	while (idx * 2 <= heap_size) {
		int smaller = idx * 2;
		if (idx * 2 + 1 <= heap_size && min_heap[idx * 2 + 1] < min_heap[smaller]) {
			smaller = idx * 2 + 1;
		}

		if (min_heap[idx] <= min_heap[smaller])
			break;

		ll temp = min_heap[smaller];
		min_heap[smaller] = min_heap[idx], min_heap[idx] = temp;
		idx = smaller;
	}

	return min_val;
}

int main() {
	read_input();
	init();

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		// 현재 line을 삽입하며, 현재의 끝점은 line[i].e가 됨
		insert(line[i].s);

		// 선분에 포함되지 못하는 link들은 제외할 것
		while (getHeapLength() > 0) {
			if (min_heap[1] < line[i].e - d) {
				pop();
			} else {
				break;
			}
		}

		// 현재 heap에 속한 line의 갯수가 '포함된 line의 갯수'가 됨
		ret = max(ret, getHeapLength());
	}
	printf("%d", ret);
	return 0;
}