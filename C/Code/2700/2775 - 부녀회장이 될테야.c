#include <stdio.h>

int main(t)
{
    int ap[15][15] = {0};       // dp
    for (int i = 0; i < 15; i++)
        for (int j = 1; j <= 14; j++)
            if (j == 1)
                ap[i][j] = 1;
            else if (!i)
                ap[i][j] = j;
            else
                ap[i][j] = ap[i - 1][j] + ap[i][j - 1]; // calc
    for (scanf("%d", &t); t; t--)
    {
        int k, n;
        scanf("%d %d", &k, &n);
        printf("%d\n", ap[k][n]);
    }
    return 0;
}