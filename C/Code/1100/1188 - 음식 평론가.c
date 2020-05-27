#include <stdio.h>

int main(n, m, result) {
	scanf("%d %d", &n, &m);
	while (n >= m)								// all person can get sausage
		n -= m;
	if (!n)										// don't need to cut sausage
		result = 0;
	else {
		int multemp = 1, i = 2;
		while (n != 1 && i <= n)				// if we only have 1 sausage, we have to cut ( person - 1 )
			if (!( n%i ) && !( m%i ))			// multemp will be GCD
				multemp *= i, n /= i, m /= i;
			else
				i++;
		result = multemp * ( m - 1 );			// eval result
	}
	printf("%d", result);
	return 0;
}

#include <stdio.h>

int main(n, m, result) {
	scanf("%d %d", &n, &m);
	n %= m;									// some sausage don't need to be cut
	int multemp = 1, i = 2;
	while (n > 1 && i <= n)					// we have to cut sausage if we have 2 or more sausage
		if (!(n % i) && !(m % i))
			multemp *= i, n /= i, m /= i;	// multemp = GCD(n, m)
		else
			i++;
	printf("%d", multemp * (m - 1) * (n != 0));	// if n == 0, don't need to cut
	return 0;
}