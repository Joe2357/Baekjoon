#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (int)(1e7 + 5)
#define SIZE_THRESHOLD ((1 << 11) - 1)
#define HASH_SIZE (int)(5e4 + 9)
#define MAX_AUX_HEAP 1500000
const int NONE = -1;
const int MAIN_THRESHOLD = 255;

unsigned long long nodes[MAX_IDX];

unsigned int main_heap[MAX_IDX];
int main_heap_size = 0;

unsigned long long aux_heap[MAX_AUX_HEAP]; // 1e7 / 255 는 대략 몇일까?
int aux_heap_size = 0;

// 해시 크기는 1e7 / (2^11) 정도면 되지 않을까?
int big_size_keys[HASH_SIZE];
int big_size_vals[HASH_SIZE];

// 비트 생성 매크로
#define MAKE_ULL(l, r, c, s) (        \
	((unsigned long long)(l) << 40) | \
	((unsigned long long)(r) << 16) | \
	((unsigned long long)(c) << 11) | \
	((unsigned long long)(s)))

// 정보 추출 매크로
#define GET_LEFT(id) ((int)(nodes[id] >> 40))				// 24bit 사용
#define GET_RIGHT(id) ((int)((nodes[id] >> 16) & 0xFFFFFF)) // 24bit 사용
#define GET_COLOR(id) ((int)((nodes[id] >> 11) & 0x1F))		// 5bit 사용 (종류가 26개까지밖에 없음)
#define GET_SIZE_RAW(id) ((int)(nodes[id] & 0x7FF))			// 나머지는 size로 사용 가능 (총 11bit, 2047까지만 저장 가능)

// 해시 함수 (size >= 2047인 경우 필요), Linear probing 해싱
void set_big_size(int id, int size) {
	int h = id % HASH_SIZE;
	while (big_size_keys[h] != 0 && big_size_keys[h] != id) {
		h = (h + 1) % HASH_SIZE;
	}
	big_size_keys[h] = id;
	big_size_vals[h] = size;
	return;
}

int get_big_size(int id) {
	int h = id % HASH_SIZE;
	while (big_size_keys[h] != 0) {
		if (big_size_keys[h] == id) {
			return big_size_vals[h];
		}
		h = (h + 1) % HASH_SIZE;
	}
	return SIZE_THRESHOLD; // 해시를 넣은게 아니라, 실제 값이 2047이라고 반환
}

int get_size(int id) {
	int s = GET_SIZE_RAW(id);
	if (s == SIZE_THRESHOLD) {
		return get_big_size(id);
	}
	return s;
}

// data 저장 함수
void save_node(int id, int left, int right, char color_char, int size) {
	int c = color_char - 'A';
	int stored_size = (size >= SIZE_THRESHOLD) ? SIZE_THRESHOLD : size;

	nodes[id] = MAKE_ULL(left, right, c, stored_size);

	if (size >= SIZE_THRESHOLD) {
		set_big_size(id, size);
	}
	return;
}

// 현재 노드의 left link 업데이트
void update_left_link(int id, int new_left) {
	unsigned long long raw = nodes[id];
	unsigned long long mask = ~((unsigned long long)0xFFFFFF << 40); // left 부분을 0으로 만드는 마스크
	nodes[id] = (raw & mask) | ((unsigned long long)new_left << 40);
	return;
}

// 현재 노드의 right link 업데이트
void update_right_link(int id, int new_right) {
	unsigned long long raw = nodes[id];
	unsigned long long mask = ~((unsigned long long)0xFFFFFF << 16); // Right 부분을 0으로 만드는 마스크
	nodes[id] = (raw & mask) | ((unsigned long long)new_right << 16);
	return;
}

// 기본 main 우선순위 큐
void push_main(unsigned int val) {
	int i = ++main_heap_size;

	while (i > 1) {
		int p = i / 2;
		if (val > main_heap[p]) {
			main_heap[i] = main_heap[p];
			i = p;
		} else {
			break;
		}
	}
	main_heap[i] = val;
	return;
}

unsigned int pop_main() {
	unsigned int ret = main_heap[1];
	unsigned int last = main_heap[main_heap_size--];

	int i = 1;
	while (i * 2 <= main_heap_size) {
		int child = i * 2;
		if (child < main_heap_size && main_heap[child + 1] > main_heap[child]) {
			child += 1;
		}
		if (main_heap[child] > last) {
			main_heap[i] = main_heap[child];
			i = child;
		} else {
			break;
		}
	}
	main_heap[i] = last;
	return ret;
}

void push_aux(unsigned long long val) {
	int i = ++aux_heap_size;

	while (i > 1) {
		int p = i / 2;
		if (val > aux_heap[p]) {
			aux_heap[i] = aux_heap[p];
			i = p;
		} else {
			break;
		}
	}
	aux_heap[i] = val;
	return;
}

unsigned long long pop_aux() {
	unsigned long long ret = aux_heap[1];
	unsigned long long last = aux_heap[aux_heap_size--];

	int i = 1;
	while (i * 2 <= aux_heap_size) {
		int child = i * 2;
		if (child < aux_heap_size && aux_heap[child + 1] > aux_heap[child]) {
			child += 1;
		}
		if (aux_heap[child] > last) {
			aux_heap[i] = aux_heap[child];
			i = child;
		} else {
			break;
		}
	}
	aux_heap[i] = last;
	return ret;
}

void mark_deleted(int id) {
	unsigned long long raw = nodes[id];
	nodes[id] = raw & ~((unsigned long long)0x7FF); // size를 0으로 변경
	return;
}

void push(int id, int size) {	 // 얘로 넣으면 알아서 해결해줄거야
	if (size < MAIN_THRESHOLD) { // 255 미만 -> Main Heap
		push_main(((unsigned int)size << 24) | (MAX_IDX - id));
	} else { // 255 이상 -> Aux Heap
		push_aux(((unsigned long long)size << 24) | (MAX_IDX - id));
	}
	return;
}

char read_char() {
	int c;
	while ((c = getchar()) <= ' ') {
		if (c == EOF) {
			return 0;
		}
	}
	return (char)c;
}

int main() {
	/* 입력 및 전처리 섹션 */
	int n, k;
	scanf("%d %d", &n, &k);

	char c = read_char();

	int current_node_idx = 1; // 1번부터 노드 번호 부여 (0은 NULL로 사용)
	int prev_node_idx = 0;	  // 0은 '이전 노드 없음'을 의미
	int target_id = NONE;	  // K번째 공이 속한 노드 번호
	int total_balls = 0;	  // 지금까지 센 공의 개수

	char prev_c = c;
	int prev_size = 1;

	for (int i = 1; i < n; ++i) {
		c = read_char();
		if (c == prev_c) {
			prev_size++;
		} else {
			if (target_id == NONE && (total_balls + prev_size >= k)) {
				target_id = current_node_idx;
			}
			total_balls += prev_size;
			save_node(current_node_idx, prev_node_idx, 0, prev_c, prev_size);
			if (prev_node_idx != 0) {
				update_right_link(prev_node_idx, current_node_idx);
			}

			push(current_node_idx, prev_size);

			prev_c = c;
			prev_size = 1;
			prev_node_idx = current_node_idx++;
		}
	}
	if (target_id == NONE && (total_balls + prev_size >= k)) {
		target_id = current_node_idx;
	}
	save_node(current_node_idx, prev_node_idx, 0, prev_c, prev_size);
	if (prev_node_idx != 0) {
		update_right_link(prev_node_idx, current_node_idx);
	}
	push(current_node_idx, prev_size);

	/* 정답 도출 및 출력 섹션 */
	int ret = 0;
	while (true) {
		int u = -1;
		int popped_size = -1;

		// [우선순위 로직] Aux Heap(거대노드)이 비어있지 않으면 무조건 우선
		if (aux_heap_size > 0) {
			unsigned long long val = pop_aux();
			u = MAX_IDX - (int)(val & 0xFFFFFF);
			popped_size = (int)(val >> 24);
		} else if (main_heap_size > 0) {
			unsigned int val = pop_main();
			u = MAX_IDX - (int)(val & 0xFFFFFF);
			popped_size = (int)(val >> 24);
		}

		int current_real_size = get_size(u);
		if (current_real_size == 0 || current_real_size != popped_size) {
			continue;
		}

		ret += 1;
		if (u == target_id) {
			break;
		}

		int left = GET_LEFT(u);
		int right = GET_RIGHT(u);
		mark_deleted(u);

		if (left != 0) {
			update_right_link(left, right);
		}
		if (right != 0) {
			update_left_link(right, left);
		}

		if (left != 0 && right != 0) {
			if (GET_COLOR(left) == GET_COLOR(right)) {
				int new_size = get_size(left) + get_size(right);
				int right_right = GET_RIGHT(right);

				save_node(left, GET_LEFT(left), right_right, (char)(GET_COLOR(left) + 'A'), new_size);
				if (right_right != 0) {
					update_left_link(right_right, left);
				}

				if (target_id == right) {
					target_id = left;
				}
				mark_deleted(right);

				push(left, new_size);
			}
		}
	}

	printf("%d", ret);
	return 0;
}