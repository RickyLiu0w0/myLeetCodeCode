/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-17
 * 57/57 (12 ms)
 * Your runtime beats 95.13 % of cpp submissions
 * Your memory usage beats 36.36 % of cpp submissions (13.4 MB)
*/
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();

        for (size_t i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }
        
        vector<int> res;
        for (auto& t : queries) {
            res.emplace_back(upper_bound(nums.begin(), nums.end(), t) - nums.begin());
        }
        return res;
    }
};
// @lc code=end

