/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-26
 * 56/56 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 26.67 % of cpp submissions (6.2 MB)
*/
class Solution {
public:
    int countDigits(int num) {
        int tmp = num, res = 0;
        while (tmp) {
            int r = tmp % 10;
            if (!(num % r)) {
                ++res;
            }
            tmp /= 10;
        }
        return res;
    }
};
// @lc code=end

