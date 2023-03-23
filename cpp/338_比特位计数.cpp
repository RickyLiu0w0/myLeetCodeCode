/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * 
 * Accepted 2023-02-12
 * 15/15 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 72.12 % of cpp submissions (7.6 MB)
*/
class Solution {
public:
    vector<int> countBits(int n) {
        /**
         * 假设X的二进制为1xxxx;
         * 假设Y的二进制为 xxxx;
         * 假设Z的二进制为10000;
         * 
         * 那么，Z = X - Y;
         * Z - 1 == 01111;
         * Z & (Z - 1) == 0;
         * dp[Z] = 1;
         * dp[X] = dp[Y] + 1;
         * dp[X] = dp[X - Z] + 1;
         */

        size_t Z = 0;
        vector<int> dp(n+1);
        dp[0] = 0;

        for (size_t X = 1; X < n + 1; ++X) {
            if ((X & (X - 1)) == 0) {
                // cout << X << endl;
                dp[X] = 1;
                Z = X;
            } else {
                dp[X] = dp[X - Z] + 1;
            }
        }

        return dp;
    }
};
// @lc code=end

