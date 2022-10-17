/*
 * @lc app=leetcode.cn id=777 lang=cpp
 *
 * [777] 在LR字符串中交换相邻字符
 */

#include "AllInclude.h"

// @lc code=start
/*
    Accepted 2022-09-29
    94/94 (12 ms)
    Your runtime beats 17.12 % of cpp submissions
    Your memory usage beats 9.46 % of cpp submissions (8.3 MB)
*/
class Solution {
public:
    bool canTransform(string start, string end) {
        queue<pair<char, size_t>> q;
        size_t i = 0;
        for (char c : start) {
            if ('X' != c) {
                q.push(pair<char, size_t>(c, i));
            }
            ++i;
        }

        i = 0;
        for (char c : end) {
            if ('X' != c) {
                if (!q.empty() && c == q.front().first) {
                    if ((c == 'L' && q.front().second >= i) || (c == 'R' && q.front().second <= i)) {
                        q.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }

            ++i;
        }

        if (!q.empty()) {
            return false;
        } else {
            return true;
        }
    }
};
// @lc code=end
/*
""RXXLRXRXL"\n
"XRLXXRRLX"\n
"XLLR"\n
"LXLX"\n
"LXLX"\n
"XLLR"\n
"LXXLXRLXXL"\n
"XLLXRXLXLX""
*/
