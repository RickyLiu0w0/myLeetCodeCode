/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include "AllInclude.h"

/**
 * Accepted 2023-03-01
 * 45/45 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 95.28 % of cpp submissions (5.7 MB)
*/

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int dp[46];

        dp[1] = 1;
        dp[2] = 2;

        for (size_t i = 3; i <=n; ++i) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
// @lc code=end

