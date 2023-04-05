/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-05
 * 469/469 (48 ms)
 * Your runtime beats 28.39 % of cpp submissions
 * Your memory usage beats 62.14 % of cpp submissions (19.2 MB)
*/
class Solution {
public:
    bool validPalindrome(string s) {
        // 判断是否回文的字串
        auto is_palindrome = [&s](int l, int r) -> bool {
            while (l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };

        int n = s.length();
        int left = 0, right = n - 1;

        while (left < right) {
            if (s[left++] != s[right--]) {
                // 左右不相等
                // 删除左边 || 删除右边 剩下的是否构成回文
                return is_palindrome(left, right + 1) ||  is_palindrome(left - 1, right);
            }
        }
        return true;
    }
};
// @lc code=end

