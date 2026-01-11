#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
        // 引数チェック
        if (begin == NULL || end == NULL) return false;
        if (begin >= end) return false;

        size_t n = end - begin;
        if (n <= 1) return true;

        // ピボットは中央
        item pivot = begin[n / 2];

        item* left = begin;
        item* right = (item*)end - 1;

        // パーティション
        while (left <= right) {
            while (item_cmp(left, &pivot) < 0) left++;
            while (item_cmp(right, &pivot) > 0) right--;

            if (left <= right) {
                item tmp = *left;
                *left = *right;
                *right = tmp;
                left++;
                right--;
            }
        }

        // 左側
        if (begin < right)
            quick_sort(begin, right + 1);

        // 右側
        if (left < end)
            quick_sort(left, end);

        return true;
    }
