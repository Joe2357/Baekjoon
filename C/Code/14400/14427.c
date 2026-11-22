#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct SegmentTreeNode {
	int min_value;
	int min_index;
} SegmentTreeNode;

#define MAX_IDX (int)(1e5)
const int ROOT = 1;

SegmentTreeNode segment_tree[4 * MAX_IDX];
int arr[MAX_IDX];
int n;

#define min(a, b) ((a) < (b) ? (a) : (b))

void make_segment_tree(int node, int start, int end) {
	if (start == end) {
		segment_tree[node] = (SegmentTreeNode){arr[start], start};
	} else {
		int mid = (start + end) / 2;
		make_segment_tree(node * 2, start, mid);
		make_segment_tree(node * 2 + 1, mid + 1, end);
		SegmentTreeNode left = segment_tree[node * 2];
		SegmentTreeNode right = segment_tree[node * 2 + 1];
		segment_tree[node] = (SegmentTreeNode){
			min(left.min_value, right.min_value),
			(left.min_value <= right.min_value) ? left.min_index : right.min_index};
	}
	return;
}

void update(int node, int start, int end, int target, int value) {
	if (target < start || target > end) {
		return;
	} else if (start == end) {
		segment_tree[node] = (SegmentTreeNode){value, target};
	} else {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, target, value);
		update(node * 2 + 1, mid + 1, end, target, value);

		SegmentTreeNode left = segment_tree[node * 2];
		SegmentTreeNode right = segment_tree[node * 2 + 1];
		segment_tree[node] = (SegmentTreeNode){
			min(left.min_value, right.min_value),
			(left.min_value <= right.min_value) ? left.min_index : right.min_index};
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	make_segment_tree(ROOT, 0, n - 1);

	int m;
	scanf("%d", &m);
	while (m--) {
		int command;
		scanf("%d", &command);
		switch (command) {
			case 1: {
				int idx, value;
				scanf("%d %d", &idx, &value);
				arr[idx - 1] = value;
				update(ROOT, 0, n - 1, idx - 1, value);
				break;
			}
			case 2: {
				printf("%d\n", segment_tree[ROOT].min_index + 1);
				break;
			}
		}
	}
	return 0;
}