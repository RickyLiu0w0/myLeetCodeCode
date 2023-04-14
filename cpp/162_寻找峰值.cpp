/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-14
 * 65/65 (4 ms)
 * Your runtime beats 73.83 % of cpp submissions
 * Your memory usage beats 72.14 % of cpp submissions (8.6 MB)
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        // 最差情况最右侧是峰顶
        int l = 0, r = n - 2;

        // 取左闭右闭，[l, r]，l - 1一定在峰顶左侧，r + 1 是顶或者右侧
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] > nums[mid + 1]) {
                // 峰顶在左边
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l; // l == r + 1
    }
};
// @lc code=end

