/*
 * @lc app=leetcode.cn id=2376 lang=cpp
 *
 * [2376] 统计特殊整数
 */

#include "AllInclude.h"

// @lc code=start
// 数位DP
class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);

        function<int(int, bool, bool, uint16_t)> f = [&](int i, bool is_limit, bool is_num, uint16_t mask) -> int {
            if (i == s.length()) {
                return is_num;  //  前面填了的话，这是一个可行结果
            }

            int res = 0;
            if (!is_num) {
                // 不选，直接跳到下一个
                res = f(i + 1, false, false, mask);
            }

            // 选
            int up = is_limit ? (s[i] - '0') : 9;
            for (int j = 1 - is_num; j <= up; ++j) {
                if ((mask & (1 << j)) == 0) {
                    // 没有填过
                    res += f(i + 1, is_limit && (j == s[i] - '0'), true, mask | (1 << j));
                }
            }
            return res;
        };

        return f(0, true, false, 0);
    }
};
// @lc code=end
