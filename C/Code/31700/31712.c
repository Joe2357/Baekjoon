#include <stdio.h>

typedef struct User {
	int cooldown, damage;
} User;

int main() {
	User a, b, c;
	int target_health;
	scanf("%d %d", &a.cooldown, &a.damage);
	scanf("%d %d", &b.cooldown, &b.damage);
	scanf("%d %d", &c.cooldown, &c.damage);
	scanf("%d", &target_health);

	int time = 0;
	for (time = 0; target_health > 0; ++time) {
		if (time % a.cooldown == 0) {
			target_health -= a.damage;
		}
		if (time % b.cooldown == 0) {
			target_health -= b.damage;
		}
		if (time % c.cooldown == 0) {
			target_health -= c.damage;
		}

		if (target_health <= 0) {
			break;
		}
	}

	printf("%d", time);
	return 0;
}