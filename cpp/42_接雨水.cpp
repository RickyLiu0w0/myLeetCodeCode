/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-23
 * 322/322 (12 ms)
 * Your runtime beats 83.95 % of cpp submissions
 * Your memory usage beats 85.85 % of cpp submissions (19.3 MB)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        // 当前水位是取决于左边最高柱子与右边最高柱子的最小值
        // 当知道一方是小值的时候，就不用关心另一方了
        // 而且该题只需求出总共水量，不需要单独求出哪一边
        int res = 0;
        // [0..left]最高，[right..n-1]最高
        int left_max = 0, right_max = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            // 相等的时候说明有一边已经算过了
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);

            if (left_max < right_max) {
                // 现在可以计算left的水量
                res += left_max - height[left++];
            } else {
                // 现在可以计算right的水量
                res += right_max - height[right--];
            }
        }
        return res;
    }
};
// @lc code=end

