/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-25
 * 111/111 (48 ms)
 * Your runtime beats 90.35 % of cpp submissions
 * Your memory usage beats 91.72 % of cpp submissions (38.8 MB)
 */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // 子数组最长为n
        int n = nums.size();
        int max_s = INT_MIN; // 最大子数组和，不能为空
        int min_s = INT_MAX; // 最小子数组和，可以为空
        int sum = 0; // 数组和
        int max_tmp = 0, min_tmp = 0;
        for (auto x : nums) {
            max_tmp = max(max_tmp, 0) + x; // 如果max_tm大于0，则对x有正面影响，将x加入。否则，x单独成一个字数组
            max_s = max(max_s, max_tmp);

            min_tmp = min(min_tmp, 0) + x; // 如果min_tm小于0，则对x有正面影响（就是要减少），将x加入。否则，x单独成一个字数组
            min_s = min(min_s, min_tmp);

            sum += x;
        }

        return sum == min_s ? max_s : max(max_s, sum - min_s);
    }
};
// @lc code=end

