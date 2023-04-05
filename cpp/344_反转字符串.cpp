/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-27
 * 477/477 (40 ms)
 * Your runtime beats 9.98 % of cpp submissions
 * Your memory usage beats 6.46 % of cpp submissions (22.7 MB)
 */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            // swap
            s[l] ^= s[r];
            s[r] ^= s[l];
            s[l] ^= s[r];
            ++l;
            --r;
        }
    }
};
// @lc code=end

