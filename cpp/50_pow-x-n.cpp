/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1;

        if (n == INT_MIN) {
            // 防止溢出
            return myPow(1 / x, -(n + 1)) / x;
        }

        if (n < 0) {
            return myPow(1/ x, -n);
        }

        // 快速幂
        if (n & 1) {
            // 奇数
            return x * myPow(x, n - 1);
        } else {
            double res = myPow(x, n / 2);
            return res * res;
        }
    }
};
// @lc code=end

