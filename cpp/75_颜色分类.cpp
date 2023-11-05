/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-04
 * 87/87 (4 ms)
 * Your runtime beats 42.35 % of cpp submissions
 * Your memory usage beats 26.89 % of cpp submissions (8.4 MB)
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0 = 0, n1 = 0;
        for (auto& num: nums) {
            int tmp = num;
            num = 2;
            if (tmp < 2) {
                nums[n1++] = 1;
            }
            if (tmp < 1) {
                nums[n0++] = 0;
            }
        }
        return;
    }
};
// @lc code=end

