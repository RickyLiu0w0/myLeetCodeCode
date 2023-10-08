/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-06
 * 109/109 (316 ms)
 * Your runtime beats 12.7 % of cpp submissions
 * Your memory usage beats 14.12 % of cpp submissions (16.7 MB)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n - 1] = 0;
        for (int i = n - 2; i > -1; --i) {
            int min_res = n;
            for (int j = i + 1; i + nums[i] >= j && j < n; ++j) {
                if (dp[j] != -1) {
                    // 能跳到
                    min_res = min(min_res, dp[j]);
                }
            }
            dp[i] = min_res + 1;
        }

        // for (auto i : dp) {
        //     cout << i << " ";
        // }
        return dp[0];
    }
};
// @lc code=end

