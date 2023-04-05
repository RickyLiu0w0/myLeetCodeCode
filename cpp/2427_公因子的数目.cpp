/*
 * @lc app=leetcode.cn id=2427 lang=cpp
 *
 * [2427] 公因子的数目
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-05
 * 76/76 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 70.09 % of cpp submissions (5.8 MB)
*/
class Solution {
    // 假设i是m的因子，那么m / i 也是m的因子，只要 m / i != i即可
public:
    int commonFactors(int a, int b) {
        int m = __gcd(a, b), res = 0;
        for (int i = 1; i * i <= m; ++i) {
            if (m % i == 0) {
                ++res;
                res += (i * i != m);
            }
        }
        return res;
    }
};
// @lc code=end
