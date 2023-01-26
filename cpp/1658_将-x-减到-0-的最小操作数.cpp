/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

#include "AllInclude.h"

/**
 * Accepted 2022-01-07
 * 94/94 (140 ms)
 * Your runtime beats 44.21 % of cpp submissions
 * Your memory usage beats 53.96 % of cpp submissions (96.2 MB)
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) {
            return -1;
        }
        int left = 0, sum = 0, res = -1, n = nums.size(), right;

        if (target == 0) {
            return n;
        }

        for (right = 0; right < n; ++right) {
            sum += nums.at(right);

            while (sum > target) {
                // left不会超过right，因为当left==right时，sum小于target
                sum -= nums.at(left++);
            }
            if (sum == target) {
                res = (res > right - left + 1) ? res : right - left + 1;
            }
        }
        return (res == -1) ? -1 : n - res;
    }
};
// @lc code=end
