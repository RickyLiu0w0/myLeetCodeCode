/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-02
 * 86/86 (100 ms)
 * Your runtime beats 49.16 % of cpp submissions
 * Your memory usage beats 35.09 % of cpp submissions (71.2 MB)
 */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j]代表从i到j的长回文子序列
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i > -1; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    // 两个都要选
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // 选其中一个
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end
