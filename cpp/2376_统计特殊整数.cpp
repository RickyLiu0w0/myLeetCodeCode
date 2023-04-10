/*
 * @lc app=leetcode.cn id=2376 lang=cpp
 *
 * [2376] 统计特殊整数
 */

#include "AllInclude.h"

// @lc code=start
// 数位DP
/**
 * Accepted 2023-04-07
 * 120/120  (16 ms)
 * Your runtime beats 69.45 % of cpp submissions
 * Your memory usage beats 63.98 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int memo[s.size()][1 << 10];
        memset(memo, -1, sizeof(memo));  // -1 表示没有计算过

        function<int(int, bool, bool, uint16_t)> f = [&](int i, bool is_limit, bool is_num, uint16_t mask) -> int {
            if (i == s.length()) {
                return is_num;  //  前面填了的话，这是一个可行结果
            }

            if (!is_limit && is_num && memo[i][mask] != -1)
                return memo[i][mask];

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

            if (!is_limit && is_num)
                memo[i][mask] = res;

            return res;
        };

        return f(0, true, false, 0);
    }
};
// @lc code=end
