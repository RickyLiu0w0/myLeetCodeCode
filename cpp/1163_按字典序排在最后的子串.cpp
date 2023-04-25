/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 *
 * [1163] 按字典序排在最后的子串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-24
 * 32/32 (32 ms)
 * Your runtime beats 87 % of cpp submissions
 * Your memory usage beats 36 % of cpp submissions (18.1 MB)
*/
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.length();
        int i = 0, j = 1, k = 0;
        while (j + k < n) {
            if (s[i + k] == s[j + k]) {
                ++k;
            } else if (s[i + k] < s[j + k]) {
                i += k + 1;
                k = 0;
                if (i >= j) {
                    j = i + 1;
                }
            } else {
                j += k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};
// @lc code=end
