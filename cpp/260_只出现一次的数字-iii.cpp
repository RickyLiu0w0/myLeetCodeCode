/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-16
 * 32/32 (4 ms)
 * Your runtime beats 97.73 % of cpp submissions
 * Your memory usage beats 23.51 % of cpp submissions (10.2 MB)
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int x = 0;
        for_each(nums.begin(), nums.end(), [&x](const int a) { x ^= a; });
        // 目前 x 是两个目标数的异或，为1的位置是两个数二进制上不同的地方，我们可以找出任意一个1
        // 最方便的话找最低的一个1
        int l = x & (-x);
        // 根据l位上1的情况分两种，将两个目标值分到两个数组中
        vector<int> res = {0, 0};
        for_each(nums.begin(), nums.end(), [&res, l](const int a) { res[(a & l) != 0] ^= a; });
        return res;
    }
};
// @lc code=end
