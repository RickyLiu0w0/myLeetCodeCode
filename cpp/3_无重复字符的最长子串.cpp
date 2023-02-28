/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include "AllInclude.h"

/**
 * Accepted 2023-02-28
 * 987/987 (16 ms)
 * Your runtime beats 70.27 % of cpp submissions
 * Your memory usage beats 55.31 % of cpp submissions (8.3 MB)
*/

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n = s.length();
        int left = 0, right = 0, res = 0;
        map<char, int> window;
        while (right < n)   {
            char c = s[right++];
            window[c]++;
            while (window[c] != 1) {
                window[s[left++]]--;
            }
            res = std::max(res, right - left);
        }
        return res;
    }
};
// @lc code=end

