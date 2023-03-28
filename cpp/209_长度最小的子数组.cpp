/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-25
 * 20/20 (36 ms)
 * Your runtime beats 35.18 % of cpp submissions
 * Your memory usage beats 55.68 % of cpp submissions (27.5 MB)
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = 0;
        int sum = 0, res = INT_MAX;
        while (r < n) {
            // 窗口往右扩展
            sum += nums[r++];

            while (l < r && sum >= target) {
                // 达到目标
                res = min(res, r - l);

                // 缩小窗口
                sum -= nums[l++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
