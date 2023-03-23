/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-11
 * 149/149 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 19.31 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};
// @lc code=end

