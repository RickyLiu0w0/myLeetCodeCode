/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-28
 * 1032/1032 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 52.77 % of cpp submissions (5.8 MB)
*/
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            int temp = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0;
            }
            res = res * 10 + temp;
        }

        return res;
    }
};
// @lc code=end
