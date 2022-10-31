/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 *
 * [2337] 移动片段得到字符串
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-09-30
    131/131 (48 ms)
    Your runtime beats 88.06 % of cpp submissions
    Your memory usage beats 71.56 % of cpp submissions (18.6 MB)
*/
class Solution {
public:
    bool canChange(string start, string target) {
        size_t s = 0, t = 0;
        size_t size = start.length();

        while (s < size) {
            if (start[s] == '_') {
                ++s;
                continue;
            }

            // 找到L或R
            char sC = start[s];
            while (t < size && target[t] == '_') {
                ++t;
            }

            if ((t == size) || (sC != target[t]) || ((sC == 'R') && (s > t)) ||
                ((sC == 'L') && (s < t))) {
                return false;
            }

            ++s;
            ++t;
        }

        while(t < size) {
            if (target[t] != '_') {
                return false;
            }
            ++t;
        }

        return true;
    }
};
// @lc code=end
/*
""R__LR_R_L"\n
"_RL__RRL_"\n
"_LLR"\n
"L_L_"\n
"R_L_"\n
"_RLR"\n
"L__L_RL__L"\n
"_LL_R_L_L_""
*/