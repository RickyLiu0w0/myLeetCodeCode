/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-04
 * 38/38 (28 ms)
 * Your runtime beats 47.33 % of cpp submissions
 * Your memory usage beats 22.92 % of cpp submissions (25 MB)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2 = nums;
        int n = nums.size(), i = 0;
        while (i < n) {
            nums[(i + k) % n] = nums2[i];
            ++i;
        }
        return;
    }
};
// @lc code=end

