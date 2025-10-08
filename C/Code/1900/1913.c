#include <stdio.h>

int main(n, getTemp) {
	scanf("%d %d", &n, &getTemp);
	int arr[999][999], xCurrent = n / 2, yCurrent = n / 2, count = 2, direction = 8, getX, getY, continuity = 1;
	arr[xCurrent][yCurrent] = 1;
	if (getTemp == 1)
		getX = xCurrent, getY = yCurrent;
	while (count <= n * n) {
		switch (direction) {
			case 8:
				for (int i = 0; i < continuity; i++) {
					arr[--yCurrent][xCurrent] = count++;
					if (count - 1 == getTemp)
						getX = xCurrent, getY = yCurrent;
				}
				direction = 6;
				break;
			case 6:
				for (int i = 0; i < continuity; i++) {
					arr[yCurrent][++xCurrent] = count++;
					if (count - 1 == getTemp)
						getX = xCurrent, getY = yCurrent;
				}
				direction = 2, continuity++;
				break;
			case 2:
				for (int i = 0; i < continuity; i++) {
					arr[++yCurrent][xCurrent] = count++;
					if (count - 1 == getTemp)
						getX = xCurrent, getY = yCurrent;
				}
				direction = 4;
				break;
			case 4:
				for (int i = 0; i < continuity; i++) {
					arr[yCurrent][--xCurrent] = count++;
					if (count - 1 == getTemp)
						getX = xCurrent, getY = yCurrent;
				}
				direction = 8, continuity++;
				break;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", getY + 1, getX + 1);
	return 0;
}