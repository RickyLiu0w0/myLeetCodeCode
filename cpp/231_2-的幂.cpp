/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-13
 * 1108/1108 cases passed (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 70.78 % of cpp submissions (5.7 MB)
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return !(n & (n - 1));
    }
};
// @lc code=end

