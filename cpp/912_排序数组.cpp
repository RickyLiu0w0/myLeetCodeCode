/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        size_t n = nums.size();
        
        // 冒泡排序
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                // j + i不会越界
                if (nums.at(j) > nums.at(j + 1)) {
                    int temp = nums.at(j);
                    nums.at(j) = nums.at(j + 1);
                    nums.at(j + 1) = temp;
                }
            }
        }

        return nums;
    }
};
// @lc code=end
