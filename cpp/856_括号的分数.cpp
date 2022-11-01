/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-09
 * 86/86 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 39.52 % of cpp submissions (6 MB)
 */
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<uint16_t> score;
        score.emplace(0);

        for (char c : s) {
            if (c == '(') {
                score.push(0);
            } else {
                uint16_t sc = score.top();
                score.pop();
                score.top() += sc ? sc << 1 : 1;

            }
        }
        return score.top();
    }
};
// @lc code=end
/*
"()"\n
"()()"\n
"(())"\n
"(()(()))"\n
"(()(((())))(((()))))(())"
*/
