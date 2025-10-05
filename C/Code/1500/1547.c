#include <stdio.h>

const int INIT_POSITION = 1;

int main() {
	int current_position = INIT_POSITION;

	int m;
	scanf("%d", &m);
	while (m--) {
		int first, second;
		scanf("%d %d", &first, &second);

		if (current_position == first) {
			current_position = second;
		} else if (current_position == second) {
			current_position = first;
		}
	}
	printf("%d", current_position);
	return 0;
}