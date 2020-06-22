#include <stdio.h>
#include <stdlib.h>
#define INFI 999999							// more than 200000
#define MAX_VERTAX 20001					// vertax will be given max 20000
#define min(a,b) (((a) < (b)) ? (a) : (b))	// min function

typedef struct Heap {				// heap tree node
	int index, distance, previous;	// index = destination, distance = how far from start, previous = previous position
} HP;

typedef struct Node {	// linked list node
	int vertax, weight;	// vertax = position, weight = cost
	struct Node* next;	// pointing next node ( link )
} ND;

int top;		// heap's top
HP heap[INFI];	// heap[999999]

ND* createNewNode(int vertax, int weight) { // create linked list node
	ND* temp = (ND*)malloc(sizeof(ND));
	temp->vertax = vertax;
	temp->weight = weight;
	temp->next = NULL;
	return temp;
}

void insertNode(ND* node, ND* start) {	// insert linked list node
	node->next = start->next;			// insert to head, head -> ¡Ù -> 3 -> 2 -> 1 -> NULL
	start->next = node;
	return;
}

void pushHeap(int index, int distance, int previous) {				// insert node to heap tree
	HP* temp = (HP*)malloc(sizeof(HP));
	temp->index = index;
	temp->distance = distance;
	temp->previous = previous;
	heap[++top] = *temp;											// insert new node to end
	free(temp);
	int tempTop = top;
	while (tempTop != 1) {											// finding right position ( heap insert )
		if (heap[tempTop].distance < heap[tempTop / 2].distance) {
			HP temp = heap[tempTop];
			heap[tempTop] = heap[tempTop / 2];
			heap[tempTop / 2] = temp;
		}
		else
			break;
		tempTop /= 2;
	}
	return;
}

HP popHeap() {
	HP temp = heap[1];										// the smallest node
	heap[1] = heap[top--];									// last node going up to head
	int i = 1, j = 2;
	while (j < top) {										// finding right position
		j += (heap[j].distance > heap[j + 1].distance);		// left or right?
		if (heap[i].distance < heap[j].distance)			// if that position is a right position
			break;
		HP swap = heap[i];									// swap their position
		heap[i] = heap[j], heap[j] = swap;
		i = j, j = 2 * i;
	}
	if (j == top && heap[i].distance > heap[j].distance) {	// only has left node & child is smaller than parents
		HP swap = heap[i];
		heap[i] = heap[j], heap[j] = swap;
	}
	return temp;											// return the smallest node
}

int main(v, e, n) {
	scanf("%d %d %d", &v, &e, &n);	// vertax, edge, start position
	ND* arr[MAX_VERTAX];			// linked list's head
	int tarr[MAX_VERTAX], visited[MAX_VERTAX] = { 0 };	// tarr = result, visited = already checked?
	for (int i = 0; i <= v; i++)	// setting all tarr Infinite
		tarr[i] = INFI;
	for (int i = 1; i <= v; i++)		// setting all linked list's head
		arr[i] = createNewNode(0, 0);
	for (; e; e--) {							// input all edge 
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		insertNode(createNewNode(b, c), arr[a]);	// link all node
		if (a == n)
			tarr[b] = min(c, tarr[b]);	// initialize tarr value ( start -> current )
	}
	tarr[n] = 0;	// start -> start = 0
	for (int i = 1; i <= v; i++)	// push 1 ~ n vertax to heap
		pushHeap(i, tarr[i], 0);
	while (top) {		// if heap is not empty
		HP heapNode = popHeap();	// pop 1 node ( smallest )
		if (heapNode.previous + heapNode.distance < tarr[heapNode.index])	// don't need to calc
			continue;
		else if (visited[heapNode.index])	// already visited
			continue;
		visited[heapNode.index] = 1;		// check visited
		ND* temp = arr[heapNode.index];		// link's destination
		while (temp) {		// link is not NULL ( have next node )
			if (temp->vertax)	// destination is not 0 == it's not head of linked list
				if (tarr[temp->vertax] > tarr[heapNode.index] + temp->weight) {		// if new way is smaller than original?
					tarr[temp->vertax] = tarr[heapNode.index] + temp->weight;		// setting new way
					pushHeap(temp->vertax, tarr[temp->vertax], heapNode.index);		// push new vertax
				}
			temp = temp->next;		// move to next link
		}
	}
	for (int i = 1; i <= v; i++)		// result printing
		if (tarr[i] == INFI)
			printf("INF\n");
		else
			printf("%d\n", tarr[i]);
	return 0;
}