/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-06
 * 200/200 (12 ms)
 * Your runtime beats 21.5 % of cpp submissions
 * Your memory usage beats 5.06 % of cpp submissions (15.2 MB)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][1] = INT_MIN;  // 不可能
        for (int i = 0; i < n; ++i) {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i]);
        }
        return dp[n][0];  // 最后一天结束不需要持有股票
    }
};
// @lc code=end

/*
[7,1,5,3,6,4]\n
[1,2,3,4,5]\n
[7,6,4,3,1]
*/