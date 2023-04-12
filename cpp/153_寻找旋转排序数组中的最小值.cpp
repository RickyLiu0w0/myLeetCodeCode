/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-11
 * 150/150 (4 ms)
 * Your runtime beats 63.91 % of cpp submissions
 * Your memory usage beats 43.29 % of cpp submissions (9.9 MB)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        // [0, n - 2]
        // (-1, n - 1)
        int n = nums.size();
        int left = -1, right = n - 1;
        while (left + 1 < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[n-1]) {
                // 在最小值的左边，最小值在nums[mid] 的右边
                left = mid;
            } else {
                // 最小值在nums[mid] 的左边
                right = mid;
            }
        }
        return nums[right];
    }

};
// @lc code=end

