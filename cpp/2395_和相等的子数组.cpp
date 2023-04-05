/*
 * @lc app=leetcode.cn id=2395 lang=cpp
 *
 * [2395] 和相等的子数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-26
 * 42/42 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 14.68 % of cpp submissions (7.6 MB)
*/
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int sum = nums[i-1] + nums[i];
            if (s.count(sum)) {
                return true;
            }
            s.insert(sum);
        }
        return false;
    }
};
// @lc code=end

