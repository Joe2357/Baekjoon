#include <stdio.h>

#define MAX_LEN 255

int main() {
	int happy = 0, sad = 0;
	char str[MAX_LEN + 2]; // 뒤 여분 1칸까지 생성
	gets(str);

	// 이모티콘 갯수 세기
	for (int i = 0; str[i] != '\0'; ++i) {
		switch (str[i]) {
			case ':': {
				if (str[i + 1] == '-') {
					sad += (str[i + 2] == '(');
					happy += (str[i + 2] == ')');
				}
			}
			default: {
				break;
			}
		}
	}

	// 결과 계산
	if (happy > sad) {
		printf("happy");
	} else if (happy < sad) {
		printf("sad");
	} else {
		if (happy == 0) {
			printf("none");
		} else {
			printf("unsure");
		}
	}
	return 0;
}