#include <stdio.h>

/*
	Trigraph 3중 문자
	3개의 연속된 문자를 하나의 문자로 대체하는 표현
	??! = |로 대체되어 출력되므로, ?나 !에 \를 붙여서 출력해야 한다
*/

int main() {
	char str[51];
	scanf("%s", str);
	printf("%s?\?!", str);
	return 0;
}