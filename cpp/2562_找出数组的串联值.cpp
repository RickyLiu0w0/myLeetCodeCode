/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-12
 * 53/53 (4 ms)
 * Your runtime beats 92.89 % of cpp submissions
 * Your memory usage beats 10.43 % of cpp submissions (9.4 MB)
*/
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        long long sum = 0;
        while (left <= right) {
            if (left == right) {
                sum += nums[left];
                break;
            }

            sum += nums[left] * pow(10, to_string(nums[right]).size()) + (long long)nums[right];
            ++left;
            --right;
        }
        return sum;
    }
};
// @lc code=end

