/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-28
 * 11510/11510 cases passed (8 ms)
 * Your runtime beats 79.14 % of cpp submissions
 * Your memory usage beats 74.32 % of cpp submissions (5.7 MB)
*/
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

