/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 *
 * [2488] 统计中位数为 K 的子数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-16
 * 45/45 cases passed (72 ms)
 * Your runtime beats 93.68 % of cpp submissions
 * Your memory usage beats 89.96 % of cpp submissions (46.7 MB)
 */
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int lo = 0, hi = 0, size = nums.size();
        if (size == 1) {
            return 1;
        }

        int mid = find(nums.begin(), nums.end(), k) - nums.begin();
        vector<int> cnt(2 * size + 1);
        int res = 1;
        for (int i = mid + 1; i < size; ++i) {
            if (nums[i] > k) {
                ++hi;
            } else {
                ++lo;
            }
            int sub = hi - lo;
            if (1 == sub || 0 == sub) {
                ++res;
            }
            cnt[sub + size]++;
        }

        lo = 0, hi = 0;
        for (int i = mid - 1; i > -1; --i) {
            if (nums[i] > k) {
                ++hi;
            } else {
                ++lo;
            }
            int sub = hi - lo;
            if (1 == sub || 0 == sub) {
                ++res;
            }
            res += (cnt[-sub + size] + cnt[size + 1 - sub]);
        }
        return res;
    }
};
// @lc code=end
