#include <stdio.h>

int main(n, getTemp) {
	scanf("%d %d", &n, &getTemp);
	int arr[999][999], xCurrent = n / 2, yCurrent = n / 2, count = 2, direction = 8, getX, getY, continuity = 1;
	arr[xCurrent][yCurrent] = 1;		// center
	if (getTemp == 1)
		getX = xCurrent, getY = yCurrent;	// first value is center
	while (count <= n * n)			// print all node
		switch (direction) {
			case 8:	// north
				for (int i = 0; i < continuity; i++) {		// continuity = how many times node move?
					arr[--yCurrent][xCurrent] = count++;	// making grid
					if (count - 1 == getTemp)				// if that position is pos we have to check
						getX = xCurrent, getY = yCurrent;
				}
				direction = 6;								// change direction
				break;
			case 6:	// east
				for (int i = 0; i < continuity; i++) {
					arr[yCurrent][++xCurrent] = count++;
					if (count - 1 == getTemp)
						getX = xCurrent, getY = yCurrent;
				}
				direction = 2, continuity++;
				break;
			case 2:	// south
				for (int i = 0; i < continuity; i++) {
					arr[++yCurrent][xCurrent] = count++;
					if (count - 1 == getTemp)
						getX = xCurrent, getY = yCurrent;
				}
				direction = 4;
				break;
			case 4:	// west
				for (int i = 0; i < continuity; i++) {
					arr[yCurrent][--xCurrent] = count++;
					if (count - 1 == getTemp)
						getX = xCurrent, getY = yCurrent;
				}
				direction = 8, continuity++;
				break;
		}
	for (int i = 0; i < n; i++) {		// print grid
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("%d %d", getY + 1, getX + 1);	// print target postion
	return 0;
}