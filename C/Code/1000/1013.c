#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 200

/* target :: (100+1+ | 01)+ */

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char str[MAX_IDX + 2 + 1] = {0};
		bool ret = true;
		scanf("%s", str);

		int len;
		for (len = 0; str[len] != '\0'; ++len) {
		}

		for (int i = 0; i < len && ret == true; ++i) {
			switch (str[i]) {
				case '0': { // 01 시퀀스
					if (str[i + 1] == '1') {
						i += 1;
						break;
					} else {
						ret = false;
						break;
					}
					break;
				}
				case '1': { // 100+1+ 시퀀스

					// 100+ 부분 확인
					ret &= (str[i + 1] == '0' && str[i + 2] == '0');
					for (i += 1; str[i] == '0'; ++i) {
					}

					// 1+ 부분 확인
					int one_count = 0;
					ret &= str[i] == '1';
					for (; str[i] == '1'; ++i) {
						one_count += 1;
					}
					int last_one_idx = i - 1;

					// 정규식 종료 부분 확인
					if (str[i] == '\0') {
						i -= 1;
						break;
					} else { // str[i] == `0`
						if (str[i + 1] != '0') {
							i -= 1;
							break;
						} else {
							ret &= (one_count > 1); // 1+ 부분이 1개 이상인지 확인
							i = last_one_idx - 1;
							break;
						}
					}
					break;
				}
			}
		}
		printf("%s\n", (ret == true) ? "YES" : "NO");
	}
	return 0;
}