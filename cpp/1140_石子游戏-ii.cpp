/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */

#include "AllInclude.h"

/**
 * Accepted 2023-02-22
 * 92/92 (20 ms)
 * Your runtime beats 65.48 % of cpp submissions
 * Your memory usage beats 73.22 % of cpp submissions (9.7 MB)
*/

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        // 计算后缀和
        size_t n = piles.size();
        int sum = 0;  // 后缀和

        vector<vector<int>> dp(n, vector<int>(n + 1));

        for (int i = n - 1; i >= 0; --i) {
            sum += piles.at(i);
            for (int M = 1; M < (n + 1); ++M) {
                if (i + 2 * M >= n) {
                    dp[i][M] = sum;
                } else {
                    for (int m = 1; m <= 2 * M; ++m) {
                        dp[i][M] = std::max(dp[i][M], sum - dp[i + m][std::max(m, M)]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};
// @lc code=end
