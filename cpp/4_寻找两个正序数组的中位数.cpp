/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-24
 * 2094/2094 (28 ms)
 * Your runtime beats 60.32 % of cpp submissions
 * Your memory usage beats 33.07 % of cpp submissions (87 MB)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 先以最短的放1的位置
        if (nums1.size() > nums2.size()) {
            vector<int> t = nums1;
            nums1 = nums2;
            nums2 = t;
        }
        
        int m = nums1.size(), n = nums2.size();
        int left_num_count = (m + n + 1) / 2; // 左边分界线的所有个数
        // 需要做到1的左边比2的右边小于等于 nums1[i - 1] <= nums2[j]
        // 而且 nums1[i] <= nums2[j - 1]
        int left = 0, right = m;
        while (left < right) {
            int i = left + (right - left + 1) / 2;
            int j = left_num_count - i;

            if (nums1[i - 1] > nums2[j]) {
                // 太靠右了，下一轮[left, i - 1]
                right = i - 1;
            } else {
                // [i, right]
                left = i;
            }
        }

        int i = left;
        int j = left_num_count - i;
        int num1_left_max = i == 0? INT_MIN : nums1[i - 1];
        int num1_right_min = i == m ? INT_MAX :nums1[i];
        int num2_right_max = j == 0 ? INT_MIN: nums2[j - 1];
        int num2_left_min = j == n? INT_MAX : nums2[j];

        if ((m + n) % 2) {
            return max(num1_left_max, num2_right_max);
        } else {
            // 偶数
            return (max(num1_left_max, num2_right_max) + min(num1_right_min, num2_left_min))/ 2.0;
        }
    }
};
// @lc code=end

