/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-13
 * 99/99 (32 ms)
 * Your runtime beats 87.2 % of cpp submissions
 * Your memory usage beats 5.01 % of cpp submissions (10.6 MB)
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto twoSumCloset = [&](int begin, int t) -> int {
            int r = nums.size() - 1;
            int last_sum = nums[begin] + nums[r];
            while (begin < r) {
                int sum = nums[begin] + nums[r];
                if (sum > t) {
                    --r;
                } else if (sum < t) {
                    ++begin;
                } else {
                    // 刚好，那直接返回
                    return sum;
                }
                if (abs(last_sum - t) > abs(sum - t)) {
                    last_sum = sum;
                }
            }
            return last_sum;
        };
        int n = nums.size();
        int res = twoSumCloset(1, target - nums[0]) + nums[0];
        for (int i = 1; i < n - 2; ++i) {
            int sub_sum = twoSumCloset(i + 1, target - nums[i]);
            if (abs(res - target) > abs(sub_sum + nums[i] - target)) {
                res = sub_sum + nums[i];
            }
        }
        return res;
    }
};
// @lc code=end
