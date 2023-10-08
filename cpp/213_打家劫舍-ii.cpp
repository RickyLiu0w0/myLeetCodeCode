/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-18
 * 75/75 (4 ms)
 * Your runtime beats 39.11 % of cpp submissions
 * Your memory usage beats 17.98 % of cpp submissions (7.9 MB)
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
        return max(dp_fun(nums, 0, n - 2), dp_fun(nums, 1, n - 1));
    }

private:
    int dp_fun(const vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};

// @lc code=end

