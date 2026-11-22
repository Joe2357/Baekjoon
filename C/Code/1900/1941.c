#include <stdio.h>

char arr[5][6];		// grid
int result;			// count

void DFS(int* sevenArr, int* visited, int x, int y) {		// DFS sub-function
	for (int i = 0; i < 7; i++)
		if (!visited[i]) {	// if not visited
			int x2 = sevenArr[i] / 5, y2 = sevenArr[i] % 5;	// position
			if (((x + 1 == x2 || x - 1 == x2) && y == y2) || (x == x2 && (y + 1 == y2 || y - 1 == y2))) {	// if adjoin
				visited[i] = 1;						// check visited
				DFS(sevenArr, visited, x2, y2);	// DFS search
			}
		}
	return;
}

void check(int* sevenArr) {					// count result
	int y = 0, s = 0;
	for (int i = 0; i < 7; i++) {
		int temp = sevenArr[i];
		switch (arr[temp / 5][temp % 5]) {	// position value?
			case 'Y':
				y++;
				break;
			case 'S':
				s++;
				break;
		}
	}
	result += (s > y);						// s > y ? 1 : 0
	return;
}

void back(int* sevenArr, int n) {									// pick 7 position
	if (n == 7) {													// if all picked
		int visited[7] = { 1 };										// first pos visited
		DFS(sevenArr, visited, sevenArr[0] / 5, sevenArr[0] % 5);	// DFS search
		for (int i = 0; i < 7; i++)
			if (!visited[i])										// if not adjoin
				return;												// condition = false
		check(sevenArr);											// count check
		return;
	}
	int tempArr[7];
	for (int i = 0; i < n; i++)							// array copy
		tempArr[i] = sevenArr[i];
	for (int i = tempArr[n - 1] + 1; i < 25; i++) {		// backtracking
		tempArr[n] = i;
		back(tempArr, n + 1);
	}
	return;
}

int main() {
	for (int i = 0; i < 5; i++)
		scanf("%s", arr[i]);
	int sevenArr[7] = { 0 };
	for (int i = 0; i < 19; i++) {
		sevenArr[0] = i;
		back(sevenArr, 1);
	}
	printf("%d", result);
	return 0;
}