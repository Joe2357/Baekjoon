#include <stdio.h>

#define MAX_IDX (int)(1e6)

int pos[MAX_IDX + 1];
int n;

int main() {
	scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
		int x;
        scanf("%d", &x);
        pos[x] = i;
    }

    int max_consecutive = 1;
    int current_len = 1;

    for (int i = 1; i < n; ++i) {
        if (pos[i] < pos[i + 1]) {
            current_len += 1;
        } else {
            if (current_len > max_consecutive) {
                max_consecutive = current_len;
            }
            current_len = 1;
        }
    }
    if (current_len > max_consecutive) {
        max_consecutive = current_len;
    }
	
    printf("%d", n - max_consecutive);
    return 0;
}