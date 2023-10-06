/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 *
 * [2865] 美丽塔 I
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-26
 * 786/786 (48 ms)
 * Your runtime beats 77.78 % of cpp submissions
 * Your memory usage beats 83.09 % of cpp submissions (23.5 MB)
*/
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        // 方法一，暴力
        // 枚举山顶，向左向右看，维护一个最小值，然后每次都加这个最小值
        // 6 5 3 9 2 7 1
        // 3 3 3 9 2 2 1
        int n = maxHeights.size();
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long sum = maxHeights[i], min_ = sum;
            // 从左看
            for (int j = i - 1; j > -1; --j) {
                min_ = min(min_, (long long)maxHeights[j]);
                sum += min_;
            }
            min_ = maxHeights[i];
            // 从右看
            for (int j = i + 1; j < n; ++j) {
                min_ = min(min_, (long long)maxHeights[j]);
                sum += min_;
            }
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end

