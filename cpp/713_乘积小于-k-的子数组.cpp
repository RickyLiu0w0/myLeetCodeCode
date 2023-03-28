/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-25
 * 97/97 cases passed (56 ms)
 * Your runtime beats 92.84 % of cpp submissions
 * Your memory usage beats 16.4 % of cpp submissions (59.9 MB)
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        size_t size = nums.size(), left = 0, right = 0;
        long long  mul = 1;
        int res = 0;
        while (right < size) {
            mul *= nums[right++];
            while (left < right && mul >= k) {
                mul /= nums[left++];
            }
            // 说明[l, r), [l + 1, r), ..., [r - 1, r)都是符合的
            // 个数为 r - 1 - l + 1 == r - l;
            res += right - left;
        }
        return res;
    }
};
// @lc code=end

