#include <stdio.h>
#define min(a, b) ((a > b) ? b : a)

int main(n, m) {
	int bundle = 1000, piece = 1000;                // max value
	for (scanf("%d %d", &n, &m); m; m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		bundle = min(bundle, a), piece = min(piece, b);     // find minimum price in purchashing line
	}
	if (bundle > 6 * piece)                                 // piece is cheaper than bundle ( 6 pieces )
		printf("%d", piece * n);
	else                                                    // bundle is cheaper than piece
		printf("%d", bundle * (n / 6) + min(bundle, (piece * (n % 6))));    // buy bundle, and buy remainder piece ( bundle or n pieces? )
	return 0;
}