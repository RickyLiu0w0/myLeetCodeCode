/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-18
 * 130/130 cases passed (4 ms)
 * Your runtime beats 88.67 % of cpp submissions
 * Your memory usage beats 74.28 % of cpp submissions (6.2 MB)
*/
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.length();
        int end = 2 * n - 1;
        // 中心扩展
        for (int i = 0; i < end; ++i) {
            int left = i / 2 ;
            int right = left + (i & 1);
            // cout << i << ": " << left << " " << right << endl;

            while (left > -1 && right < n && s[left] == s[right]) {
                --left;
                ++right;
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
/*
"accccb"\n
"acccca"\n
"ccc"\n
"cc"\n
"acccbccca"
*/
