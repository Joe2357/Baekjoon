#include <stdio.h>

#define MAX_IDX (int)(5e6)
int arr[MAX_IDX];

int cmp(int *a, int* b) {
    return *a > *b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    
    qsort(arr, n, sizeof(int), cmp);
    
    printf("%d", arr[k-1]);
    return 0;
}