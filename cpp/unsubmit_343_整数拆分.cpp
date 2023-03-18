/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(59);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            int num = 0;
            int mid = i >> 1;
            for (int j = 1; j <= mid; ++j) {
                num = std::max(num, std::max(dp[j] * dp[i - j], std::max(j * dp[i - j], std::max(dp[j] * (i - j), j * (i - j)))));
            }
            dp[i] = num;
            // cout << "i: " << i << " num: " << num << endl;
        }
        return dp[n];
    }
};
// @lc code=end
