/*
 * @lc app=leetcode.cn id=1012 lang=cpp
 *
 * [1012] 至少有 1 位重复的数字
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-20
 * 129/129 (608 ms)
 * Your runtime beats 6.67 % of cpp submissions
 * Your memory usage beats 89.09 % of cpp submissions (5.8 MB)
*/
class Solution {
// 数位DP
public:
    int numDupDigitsAtMostN(int n) {
        // 利用mask存储填过数字的集合
        s = to_string(n);
        return n - dp(0, 0, true, false);
    }
private:
    string s;
    // 返回从第i位开始填数字，已填集合为mask，能够构造出至少一位重复数字的个数
    // is_limit，检查前面的数字是否都是n对应位上的，如果为 true 则第i位只能填s[i]，否则可以最高填9
    // is_num，检查前面是否以前填过数字，ture则前面填过，第i位可以填0-9；如果为 false，我们可以跳过，或者第i位置只能填1-x，x由is_limit约束

    int dp(int i, int mask, bool is_limit, bool is_num) {
        if (i == s.length()) {
            // 已经构造出结果，如果前面填了数字，则返回结果一
            return is_num;
        }

        int res = 0;

        if (!is_num) {
            // 前面没有数字，可以跳过
            res = dp(i + 1, mask, false, false);
        }

        int up = is_limit ? (s[i] - '0') : 9;

        // 枚举
        for (int j = 1 - is_num; j < up + 1; ++j) {
            //判断是否已经选过
            if ((mask & (1 << j)) == 0) {
                // 填进去
                res += dp(i + 1, mask | (1 << j), is_limit && j == up, true);
            }
        }
        return res;
    }
};
// @lc code=end

