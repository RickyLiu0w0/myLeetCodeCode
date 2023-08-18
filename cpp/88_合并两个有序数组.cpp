/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-13
 * 59/59 (4 ms)
 * Your runtime beats 53.29 % of cpp submissions
 * Your memory usage beats 9.92 % of cpp submissions (9 MB)
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int res_ptr = m + n - 1, ptr1 = m - 1, ptr2 = n - 1;
        while (ptr1 > -1 || ptr2 > -1) {
            if (ptr2 < 0 || (ptr1 > -1 && nums1[ptr1] > nums2[ptr2])) {
                nums1[res_ptr--] = nums1[ptr1--];
            } else {
                nums1[res_ptr--] = nums2[ptr2--];
            }
        }
        return;
    }
};
// @lc code=end

