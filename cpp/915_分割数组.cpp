/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-10-24
 * 66/66 (120 ms)
 * Your runtime beats 78.36 % of cpp submissions
 * Your memory usage beats 59.32 % of cpp submissions (92.1 MB)
*/
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int maxL = nums[0];
        int maxR = nums[1];
        size_t mid = 1;
        size_t size = nums.size() - 1;

        for (size_t ptr = 1; ptr < size; ++ptr) {
            if (maxL > nums[ptr]) {
                maxL = maxR > maxL ? maxR : maxL;
                mid = ptr + 1;
                maxR = nums[mid];
            } else {
                maxR = maxR < nums[ptr] ? nums[ptr] : maxR;
            }
        }

        return mid;
    }
};
// @lc code=end
/*
[5,0,3,8,6]\n
[1,1,1,0,6,12]\n
[1,0,1,0,6,2,0,12]\n
[6,0,8,30,37,6,75,98,39,90,63,74,52,92,64]
*/