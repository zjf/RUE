#include "khash.h"
KHASH_MAP_INIT_INT(32, char)
int main() {
	int ret, is_missing;
	khiter_t k;
	khash_t(32) *h = kh_init(32);
	k = kh_put(32, h, 5, &ret);
	kh_value(h, k) = 10;
    printf("h[5] = %d\n", kh_value(h, k));
	k = kh_get(32, h, 10);
	is_missing = (k == kh_end(h));
    printf("h[10] = %d\n", kh_value(h, k));
	k = kh_get(32, h, 5);
	kh_del(32, h, k);
	for (k = kh_begin(h); k != kh_end(h); ++k)
		if (kh_exist(h, k)) kh_value(h, k) = 1;
	kh_destroy(32, h);
	return 0;
}
