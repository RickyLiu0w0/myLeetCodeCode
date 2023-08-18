/*
 * @lc app=leetcode.cn id=2682 lang=cpp
 *
 * [2682] 找出转圈游戏输家
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-16
 * 1277/1277 (8 ms)
 * Your runtime beats 73.56 % of cpp submissions
Your memory usage beats 74.7 % of cpp submissions (8.4 MB)
 */
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> v(51, true);
        size_t ptr = 1, count = 1;
        while (v[ptr]) {
            v[ptr] = false;
            ptr = (ptr - 1 + count++ * k) % n + 1;
        }

        vector<int> res;
        ptr = 1;
        while (ptr <= n) {
            if (v[ptr]) {
                res.emplace_back(ptr);
            }
            ++ptr;
        }
        return res;
    }
};
// @lc code=end
