/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-06
 * 214/214 (944 ms)
 * Your runtime beats 5 % of cpp submissions
 * Your memory usage beats 4.97 % of cpp submissions (266.8 MB)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_k = 2, n = prices.size();
        // dp[n][k][0/1] 表示第n天结束后交易了k次，当前状态持有或不持有
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < max_k; ++k) {
                if (i == 0) {
                    dp[0][k + 1][1] = INT_MIN;
                }
                dp[i + 1][k + 1][0] = max(dp[i][k + 1][0], dp[i][k + 1][1] + prices[i]);
                dp[i + 1][k + 1][1] = max(dp[i][k + 1][1], dp[i][k][0] - prices[i]);
            }
        }
        return dp[n][max_k][0];
    }
};
// @lc code=end
