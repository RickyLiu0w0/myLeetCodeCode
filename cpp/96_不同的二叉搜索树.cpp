/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-29
 * 19/19 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 47.84 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    int numTrees(int n) {
        /**
         * 卡特兰数
         * dp[i]定义为有i个节点的BST
         * dp[0] = 1
         * dp[1] = 1
         * dp[2] = dp[0] * dp[1] + dp[1] * dp[0]
         * dp[3] = dp[0] * dp[2] + dp[1] * dp[1] + dp[2] * dp[0]
         * dp[i] = Sum(dp[j] * dp[i - j - 1]) 0 <= j < i
         * 定住i遍历j
         */
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i ; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            } 
        }
        return dp[n];
    }
};
// @lc code=end

