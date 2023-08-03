#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Node {
	int v;
	int idx;
} ND;

#define MAX_ITER (int)(1e6)
const int HEAD = 1;

bool deleted[MAX_ITER + 1];
ND maxH[MAX_ITER * 2 + 100], minH[MAX_ITER * 2 + 100];
int maxT, minT, remained;

bool isQueueEmpty() { return remained == 0; }
void insertMaxH(ND x) {
	maxH[++maxT] = x;
	int i = maxT;

	while (i > 1 && x.v > maxH[i / 2].v) {
		ND a = maxH[i / 2];
		maxH[i / 2] = x, maxH[i] = a;
		i /= 2;
	}
	return;
}
void insertMinH(ND x) {
	minH[++minT] = x;
	int i = minT;

	while (i > 1 && x.v < minH[i / 2].v) {
		ND a = minH[i / 2];
		minH[i / 2] = x, minH[i] = a;
		i /= 2;
	}
	return;
}

void deleteMaxValue() {
	bool isExitable = false;
	do {
		if (isQueueEmpty() == false) {
			ND retval = maxH[HEAD];
			maxH[HEAD] = maxH[maxT--];

			int i = HEAD, tp = i * 2;
			while (tp < maxT) {
				tp += (maxH[tp].v < maxH[tp + 1].v);
				if (maxH[i].v >= maxH[tp].v) {
					break;
				}

				ND a = maxH[tp];
				maxH[tp] = maxH[i], maxH[i] = a;

				i = tp, tp *= 2;
			}
			if (tp == maxT && maxH[i].v < maxH[tp].v) {
				ND a = maxH[tp];
				maxH[tp] = maxH[i], maxH[i] = a;
			}

			if (deleted[retval.idx] == false) {
				deleted[retval.idx] = true;
				isExitable = true;
			}
		} else {
			isExitable = true;
		}
	} while (isExitable == false);
	return;
}
void deleteMinValue() {
	bool isExitable = false;
	do {
		if (isQueueEmpty() == false) {
			ND retval = minH[HEAD];
			minH[HEAD] = minH[minT--];

			int i = HEAD, tp = i * 2;
			while (tp < minT) {
				tp += (minH[tp].v > minH[tp + 1].v);
				if (minH[i].v <= minH[tp].v) {
					break;
				}

				ND a = minH[tp];
				minH[tp] = minH[i], minH[i] = a;

				i = tp, tp *= 2;
			}
			if (tp == minT && minH[i].v > minH[tp].v) {
				ND a = minH[tp];
				minH[tp] = minH[i], minH[i] = a;
			}

			if (deleted[retval.idx] == false) {
				deleted[retval.idx] = true;
				isExitable = true;
			}
		} else {
			isExitable = true;
		}
	} while (isExitable == false);
	return;
}

void cleanMaxH() {
	while (deleted[maxH[HEAD].idx] == true) {
		ND retval = maxH[HEAD];
		maxH[HEAD] = maxH[maxT--];

		int i = HEAD, tp = i * 2;
		while (tp < maxT) {
			tp += (maxH[tp].v < maxH[tp + 1].v);
			if (maxH[i].v >= maxH[tp].v) {
				break;
			}

			ND a = maxH[tp];
			maxH[tp] = maxH[i], maxH[i] = a;

			i = tp, tp *= 2;
		}
		if (tp == maxT && maxH[i].v < maxH[tp].v) {
			ND a = maxH[tp];
			maxH[tp] = maxH[i], maxH[i] = a;
		}
	}
	return;
}
void cleanMinH() {
	while (deleted[minH[HEAD].idx] == true) {
		ND retval = minH[HEAD];
		minH[HEAD] = minH[minT--];

		int i = HEAD, tp = i * 2;
		while (tp < minT) {
			tp += (minH[tp].v > minH[tp + 1].v);
			if (minH[i].v <= minH[tp].v) {
				break;
			}

			ND a = minH[tp];
			minH[tp] = minH[i], minH[i] = a;

			i = tp, tp *= 2;
		}
		if (tp == minT && minH[i].v > minH[tp].v) {
			ND a = minH[tp];
			minH[tp] = minH[i], minH[i] = a;
		}
	}
	return;
}

void init() {
	for (int i = 0; i < MAX_ITER; ++i) {
		deleted[i] = false;
	}
	maxT = 0, minT = 0, remained = 0;
	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		init();

		int k;
		scanf("%d", &k);

		for (int i = 0; i < k; ++i) {
			char command[3];
			int x;
			scanf("%s %d", command, &x);

			switch (command[0]) {
				case 'I': {
					insertMaxH((ND){x, i});
					insertMinH((ND){x, i});
					++remained;
				} break;
				case 'D': {
					if (isQueueEmpty() == false) {
						--remained;
						switch (x) {
							case 1: {
								deleteMaxValue();
							} break;
							case -1: {
								deleteMinValue();
							} break;
						}
					}
				} break;
			}

			if (remained == 0) {
				maxT = minT = 0;
			}
		}

		if (isQueueEmpty() == true) {
			printf("EMPTY\n");
		} else {
			cleanMaxH();
			cleanMinH();
			printf("%d %d\n", maxH[HEAD], minH[HEAD]);
		}
	}

	return 0;
}