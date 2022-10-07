/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-10-01
    115/115 (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 23.37 % of cpp submissions (6.1 MB)
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, stack = 0;
        for (char c : s) {
            if ('(' == c) {
                ++stack;
            } else {
                if (stack) {
                    --stack;
                } else {
                    ++res;
                }
            }
        }
        return res + stack;
    }
};
// @lc code=end
/*
"())"\n
"((("\n
"()))"\n
"(()))"\n
"())))"\n
"()))(("\n
")))((("\n
"(()())(("
*/