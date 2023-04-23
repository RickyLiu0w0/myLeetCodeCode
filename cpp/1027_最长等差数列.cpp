/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-22
 * 63/63 (428 ms)
 * Your runtime beats 22.37 % of cpp submissions
 * Your memory usage beats 62.06 % of cpp submissions (99.9 MB)
 */
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        /**
         * 现有k < j < i
         * aj - ak = ai - aj
         * 2 * aj - ai = ak
         */

        int n = nums.size();
        int res = 0;

        vector<unordered_map<int, int>> dp(n);  // 以nums[i]为结尾的 <d, len>
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j > -1; --j) {
                int d = nums[i] - nums[j];
                if (!dp[i].count(d)) {
                    auto it = dp[j].find(d);
                    dp[i][d] = it == dp[j].end() ? 2 : it->second + 1;
                    res = max(res, dp[i][d]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
