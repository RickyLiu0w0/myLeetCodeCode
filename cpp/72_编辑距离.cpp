/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-04
 * 1146/1146 (12 ms)
 * Your runtime beats 81.59 % of cpp submissions
 * Your memory usage beats 9.14 % of cpp submissions (9.3 MB)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = j; // 只剩另一个字符串，则要把另一个的长度记录下来
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

