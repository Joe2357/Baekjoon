#include <stdio.h>

void get_smallest(int x) {
	// 가능하다면 8을 최대한 쓰는 것이 이득
	// 사용되는 숫자가 모두 8보다 작으므로, 8을 활용해 최대한 자릿수를 줄이고,
	// 남은 자투리는 작은 숫자를 활용해 앞에 배치

	switch (x % 7) {
		case 0: {
			break; // 8을 사용할 예정
		}
		case 1: {
			printf("10");
			x -= 8; // 1칸만 사용해서 숫자를 만들수는 없음
			break;
		}
		case 2: {
			printf("1");
			x -= 2;
			break;
		}
		case 3: {
			if (x == 3) {
				printf("7");
				x -= 3;
			} else if (x == 10) {
				printf("22");
				x -= 10;
			} else {
				printf("200");
				x -= 17;
			}
			break;
		}
		case 4: {
			if (x == 4) {
				printf("4");
				x -= 4;
			} else {
				printf("20");
				x -= 11;
			}
			break;
		}
		case 5: {
			printf("2");
			x -= 5;
			break;
		}
		case 6: {
			printf("6");
			x -= 6;
			break;
		}
	}
	while (x > 0) {
		printf("8");
		x -= 7;
	}
	return;
}

void get_biggest(int x) {
	// 1111111 혹은 7111111이 최대
	if (x % 2 == 1) {
		printf("7");
		x -= 3;
	}
	while (x > 0) {
		printf("1");
		x -= 2;
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		get_smallest(n);
		printf(" ");
		get_biggest(n);
		printf("\n");
	}
	return 0;
}