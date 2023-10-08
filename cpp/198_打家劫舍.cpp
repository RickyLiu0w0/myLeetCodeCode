/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-18
 * 70/70 (4 ms)
 * Your runtime beats 37.15 % of cpp submissions
 * Your memory usage beats 9.82 % of cpp submissions (8 MB)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            // first 是偷 i - 2家时候的答案
            int t = second;
            second = max(second, first + nums[i]);
            first = t;
        }
        return second;
    }
};
// @lc code=end

