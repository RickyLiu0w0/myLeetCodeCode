/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-05
 * 485/485 (4 ms)
 * Your runtime beats 86.08 % of cpp submissions
 * Your memory usage beats 54.84 % of cpp submissions (7.3 MB)
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length();

        while (l < r) {
            while (l < r && (!isalpha(s[l]) && !isdigit(s[l]))) {
                ++l;
            }

            while (l < r && (!isalpha(s[r]) && !isdigit(s[r]))) {
                --r;
            }

            if (isalpha(s[l])) {
                s[l] |= ' ';
            }

            if (isalpha(s[r])) {
                s[r] |= ' ';
            }

            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

