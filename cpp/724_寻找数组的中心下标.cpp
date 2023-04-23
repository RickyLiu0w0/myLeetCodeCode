/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-22
 * 746/746 (16 ms)
 * Your runtime beats 87.72 % of cpp submissions
 * Your memory usage beats 9.17 % of cpp submissions (30.9 MB)
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 前缀和
        // S_n - S_{i} == S_{i - 1}
        int n = nums.size();
        vector<int> pre_sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }

        int i = 0;  // i 为 [0, n)
        while (i < n) {
            if (pre_sum[n] - pre_sum[i+1] == pre_sum[i]) {
                break;
            }
            i++;
        }
        return i == n ? -1 : i;
    }
};
// @lc code=end
