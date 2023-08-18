/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-07
 * 176/176 (48 ms)
 * Your runtime beats 80.01 % of cpp submissions
 * Your memory usage beats 55.46 % of cpp submissions (40.2 MB)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 获取数组长度n，小于1和大于n的数都不用管
        int n = nums.size();

        //  期待[1, n] ,num[i]的数字应该在i - 1上
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] < n) {
                int t = nums[i];
                if (t == nums[t - 1]) {
                    continue;
                }
                nums[i] = nums[t - 1];
                nums[t - 1] = t;
                --i;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
// @lc code=end

