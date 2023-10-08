/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-+10-06
 * 210/210 (4 ms)
 * Your runtime beats 75.93 % of cpp submissions
 * Your memory usage beats 5.33 % of cpp submissions (12 MB)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        dp[1][1] = INT_MIN;
        for (int i = 0; i < n; ++i) {
            dp[i + 2][0] = max(dp[i + 1][0], dp[i + 1][1] + prices[i]);
            dp[i + 2][1] = max(dp[i + 1][1], dp[i][0] - prices[i]);
        }
        return dp[n + 1][0];
    }
};
// @lc code=end

