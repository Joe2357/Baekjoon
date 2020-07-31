#include <stdio.h>
#define min(a, b) (a > b) ? b : a
#define MAX_INDEX 1000000

typedef struct Line {
	int start, end;
} LN;

int cmp(LN *a, LN *b) {
	return (a->end > b->end) || (a->end == b->end) && (a->start > b->start);
}

int main() {
	// init
	LN stack[MAX_INDEX];
	int top, result = 0;
	scanf("%d", &top);
	for (int i = 0; i < top; i++)
		scanf("%d %d", &stack[i].start, &stack[i].end);

	// sort
	qsort(stack, top, sizeof(LN), cmp);

	// calc stack
	for (--top; top > 0; top--)
		// no match
		if (stack[top].start > stack[top - 1].end)
			result += stack[top].end - stack[top].start;
		else // have match
			stack[top - 1] = (LN) { min(stack[top - 1].start, stack[top].start), stack[top].end };

	// last pop
	result += (stack[0].end - stack[0].start);

	// print result
	printf("%d", result);
	return 0;
}