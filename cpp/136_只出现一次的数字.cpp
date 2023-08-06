/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-03
 * 61/61 (16 ms)
 * Your runtime beats 67.99 % of cpp submissions
 * Your memory usage beats 78.24 % of cpp submissions (16.4 MB)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto& num : nums) {
            res ^= num;
        }
        return res;
    }
};
// @lc code=end

