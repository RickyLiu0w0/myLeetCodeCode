/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-03
 * 141/141 (396 ms)
 * Your runtime beats 17.63 % of cpp submissions
 * Your memory usage beats 90.95 % of cpp submissions (9.7 MB)
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        sum = sum >> 1;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = sum ; j >= 0; --j) {
                if (j - nums[i] >= 0) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }
        return dp[sum];
    }
};
// @lc code=end

