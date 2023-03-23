/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-23
 * 596/596 (16 ms)
 * Your runtime beats 36.05 % of cpp submissions
 * Your memory usage beats 75.91 % of cpp submissions (7.4 MB)
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int tmp[3] = {1, 1, 1};
        for (int i = 2; i <= n; ++i) {
            if (dp[tmp[0]] * 2 < dp[tmp[1]] * 3) {
                if (dp[tmp[0]] * 2 < dp[tmp[2]] * 5) {
                    dp[i] = dp[tmp[0]] * 2;
                    ++tmp[0];
                } else {
                    dp[i] = dp[tmp[2]] * 5;
                    ++tmp[2];
                }
            } else {
                if (dp[tmp[1]] * 3 < dp[tmp[2]] * 5) {
                    dp[i] = dp[tmp[1]] * 3;
                    ++tmp[1];
                } else {
                    dp[i] = dp[tmp[2]] * 5;
                    ++tmp[2];
                }
            }

            if (dp[i] == dp[i - 1]) {
                i--;
            }
        }

        return dp[n];
    }
};
// @lc code=end
