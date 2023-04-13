/*
 * @lc app=leetcode.cn id=2399 lang=cpp
 *
 * [2399] 检查相同字母间的距离
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-09
 * 335/335 (8 ms)
 * Your runtime beats 40.69 % of cpp submissions
 * Your memory usage beats 74.48 % of cpp submissions (12.7 MB)
 */
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '%') {
                continue;
            }

            if (distance[c - 'a'] + i + 1 >= n) {
                return false;
            } 

            if (s[distance[c - 'a'] + i + 1] != c) {
                return false;
            } else {
                s[distance[c - 'a'] + i + 1] = '%';
            }
        }
        return true;
    }
};
// @lc code=end
/*
"ttkk"\n[10,14,9,10,11,50,11,26,32,13,31,8,18,2,34,10,15,5,20,19,10,20,5,24,22,10]
*/
