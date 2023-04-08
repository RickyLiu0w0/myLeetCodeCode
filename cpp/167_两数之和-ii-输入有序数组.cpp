/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-08
 * 23/23 (16 ms)
 * Your runtime beats 29.28 % of cpp submissions
 * Your memory usage beats 30.84 % of cpp submissions (15.2 MB)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int l = 0, r = n - 1;
        while (l < r) {
            if (numbers.at(l) + numbers.at(r) > target) {
                --r;
            } else if (numbers.at(l) + numbers.at(r) == target) {
                return {l + 1, r + 1};
            } else {
                ++l;
            }
        }

        return {};
    }
};
// @lc code=end

