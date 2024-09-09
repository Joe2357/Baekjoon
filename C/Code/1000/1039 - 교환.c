#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e6)

bool visit[MAX_IDX + 1];
int n, k;
int digit;

int queue[MAX_IDX + 1];
int front, rear;
bool isCandidateExists;

void clear() {
    for (int i = 0; i <= MAX_IDX; ++i) {
        visit[i] = false;
    }
    isCandidateExists = false;
    return;
}

int getDigit(int x, int a) {
    for (int i = 0; i < a; ++i) {
        x /= 10;
    }
    return x % 10;
}

int swap(int x, int a, int b) {
    int c = 1, d = 1;
    for (int i = 0; i < a; ++i) {
        c *= 10;
    }
    for (int i = 0; i < b; ++i) {
        d *= 10;
    }

    int e = (x / c) % 10, f = (x / d) % 10;
    int ret = x - (e * c) - (f * d) + (f * c) + (e * d);

    return ret;
}

int main() {
    scanf("%d %d", &n, &k);
    visit[n] = true;

    int temp = n;
    while (temp > 0) {
        temp /= 10;
        ++digit;
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= MAX_IDX; ++j) {
            if (visit[j] == true) {
                queue[rear++] = j;
            }
        }
        clear();

        while (front < rear) {
            int x = queue[front++];
            for (int a = 0; a < digit; ++a) {
                for (int b = a + 1; b < digit; ++b) {
                    if (b == digit - 1 && getDigit(x, a) == 0) {
                        continue;
                    }
                    visit[swap(x, a, b)] = true;
                    isCandidateExists = true;
                }
            }
        }

        front = rear = 0;
        if (isCandidateExists == false) {
            printf("-1");
            return 0;
        }
    }

    for (int i = MAX_IDX; i >= 0; --i) {
        if (visit[i] == true) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}