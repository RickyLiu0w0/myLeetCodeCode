/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-05
 * 266/266 (8 ms)
 * Your runtime beats 25.61 % of cpp submissions
 * Your memory usage beats 65.81 % of cpp submissions (11.8 MB)
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1  3  6  5  4  2 找到第一个顺序的地方（3，5）说明逆序的地方都已经排好了，没得动了，考虑往前进一位
        // 1  4  6  5  3  2 交换刚好比3大的数字（3，4）相当于进一位
        // 1  4  2  3  5  6 将进位后右边的树排成顺序，就是最小的
        int n = nums.size();
        int i = n - 2;
        for (; i > - 1; --i) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }

        // 找到第一个顺序的地方
        if (i == -1) {
            // 全体逆序，重排就好
            sort(nums.begin(), nums.end());
            return;
        }

        // 从后面找到第一个比nums[i]大的数
        int j = n - 1;
        for (; j > i ; --j) {
            if (nums[j] > nums[i]) {
                break;
            }
        }

        // swap i j
        if (i != j) {
            nums[i] ^= nums[j];
            nums[j] ^= nums[i];
            nums[i] ^= nums[j];
        }

        // 重排i后面的
        sort(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

