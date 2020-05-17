#include <stdio.h>
#include <math.h>														// using sqrt, pow function ( a ^ (1/2) , a ^ b )
 
int main(t) {
	for (scanf("%d", &t); t; t--) {
		int x1, x2, y1, y2, result = 0, n;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (scanf("%d", &n); n; n--) {
			int x, y, r, temp = 0;
			scanf("%d %d %d", &x, &y, &r);
			temp += sqrt(pow(( x1 - x ), 2) + pow(( y1 - y ), 2)) > r;	// start point in circle? ? 0 : 1
			temp += sqrt(pow(( x2 - x ), 2) + pow(( y2 - y ), 2)) > r;	// end point in circle? ? 0 : 1
			result += temp % 2;											// start point & end point are not in same area
		}
		printf("%d\n", result);
	}
	return 0;
}