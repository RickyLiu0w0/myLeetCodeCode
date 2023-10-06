/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-06
 * 44/44 (172 ms)
 * Your runtime beats 52.11 % of cpp submissions
 * Your memory usage beats 7.81 % of cpp sub
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][1] = INT_MIN + fee;
        for (int i = 0; i < n; ++i) {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i] - fee);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i]);
        }
        return dp[n][0];
    }
};
// @lc code=end

/*
[1,3,2,8,4,9]\n2\n
[1,3,7,5,10,3]\n3
*/