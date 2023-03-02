/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include "AllInclude.h"

// @lc code=start

/**
 * Accepted 2023-03-02
 * 210/210 (84 ms)
 * Your runtime beats 80.32 % of cpp submissions
 * Your memory usage beats 92.14 % of cpp submissions (66 MB)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t n = nums.size();

        int dp_0 = -10000, dp_1, res = INT_MIN;

        for (auto & num : nums) {
            dp_1 = std::max(num, num + dp_0);
            res = std::max(dp_1, res);
            dp_0 = dp_1;
        }
        return res;
    }
};
// @lc code=end

