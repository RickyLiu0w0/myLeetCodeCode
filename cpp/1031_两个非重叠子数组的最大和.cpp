/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-26
 * 51/51 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 70.74 % of cpp submissions (8.3 MB)
*/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> pre_sum(n + 1);
        pre_sum[0] = 0;
        partial_sum(nums.begin(), nums.end(), pre_sum.begin() + 1);
        int maxA = 0, maxB = 0, res = 0;
        for (int i = firstLen + secondLen; i <= n; ++i) {
            maxA = max(maxA, pre_sum[i - secondLen] - pre_sum[i - firstLen - secondLen]);
            maxB = max(maxB, pre_sum[i - firstLen] - pre_sum[i - firstLen - secondLen]);
            res = max(res, max(maxA + pre_sum[i] - pre_sum[i - secondLen], maxB + pre_sum[i] - pre_sum[i - firstLen]));
        }
        return res;
    }
};
// @lc code=end
