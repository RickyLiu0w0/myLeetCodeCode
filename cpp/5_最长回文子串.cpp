/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-13
 * 141/141 (20 ms)
 * Your runtime beats 70.91 % of cpp submissions
 * Your memory usage beats 73.89 % of cpp submissions (7.3 MB)
 */
class Solution {
public:
    string longestPalindrome(string s) {
        // 中心扩展法
        int size = s.length();
        int max_length = 1;
        string res;
        res.push_back(s.front());
        auto f = [&](int center) {
            int left = center - 1;
            int right = center + 1;

            // 先只扩左边，再扩右边，扩展到外面不相同的部分
            while (left > -1 && s[left] == s[center]) {
                left--;
                while (right < size && s[right] == s[center]) {
                    right++;
                }
            }

            // 开始左右两边扩
            while (left > -1 && right < size && s[left] == s[right]) {
                left--;
                right++;
            }

            // (left, rifht) 是回文，左开右开
            if (max_length < right - left - 1) {
                max_length = right - left - 1;
                res = s.substr(left + 1, max_length);
            }
        };
        for (int i = 0; i < size; ++i) {
            f(i);
        }
        return res;
    }
};
// @lc code=end
/*
"1234"\n
"1"\n
"babad"\n
"cbbd"\n
"1cbbc2"\n
"1cbbc1"\n
"cccc"\n
"ccc"\n
"cc"
*/
