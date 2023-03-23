/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-21
 * 47/47 (64 ms)
 * Your runtime beats 15.39 % of cpp submissions
 * Your memory usage beats 30.1 % of cpp submissions (23.8 MB)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 获取tex1长度
        int len1 = text1.size();
        int len2 = text2.size();

        // 初始化dp数组
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end
