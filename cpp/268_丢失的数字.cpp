/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

#include "AllInclude.h"
/**
 * Accepted 2023-03-14
 * 122/122 (12 ms)
 * Your runtime beats 93.1 % of cpp submissions
 * Your memory usage beats 79.33 % of cpp submissions (17.4 MB)
*/

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;
        res ^= n;
        for (int i = 0; i < n; ++i) {
            res ^= (i ^ nums.at(i));
        }
        return res;
    }
};
// @lc code=end

