/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-07
 * 58/58 (92 ms)
 * Your runtime beats 58.92 % of cpp submissions
 * Your memory usage beats 13.67 % of cpp submissions (59.9 MB)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 如果nums[i]不在如果nums[i] - 1上，且nums[i] - 1的位置上已经存在了正确的数字，则此数字为重复数字
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1 ) {
                int t = nums[i];
                if (nums[t - 1] == t) {
                    return t;
                }
                nums[i] = nums[t - 1];
                nums[t - 1] = t;
                --i;
            }
        }
        return -1;
    }
};
// @lc code=end

