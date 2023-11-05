/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-01
 * 189/189 (92 ms)
 * Your runtime beats 33.09 % of cpp submissions
 * Your memory usage beats 39.78 % of cpp submissions (14.4 MB)
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) {
            return 0;
        }

        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int min_num = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (coins[j] <= i) {
                    if (dp[i - coins[j]] != INT_MAX)
                        min_num = min(min_num, dp[i - coins[j]] + 1);   
                } else {
                    break;
                }
            }
            dp[i] = min_num;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end

