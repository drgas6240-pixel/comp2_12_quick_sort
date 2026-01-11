#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct item_
	{
		int key;
		char value[256];
	}item;

	// クイックソート(引数が不適切であればfalseを返す)
	bool quick_sort(item *begin, const item* end);

	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif

// 2つのitemを比較する関数（keyで比較）
// a < b: 負値, a == b: 0, a > b: 正値
static inline int item_cmp(const item* a, const item* b)
{
    if (a->key < b->key) return -1;
    if (a->key > b->key) return 1;
    return 0;
}
