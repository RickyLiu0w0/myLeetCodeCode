/*
 * @lc app=leetcode.cn id=1664 lang=cpp
 *
 * [1664] 生成平衡数组的方案数
 */

#include "AllInclude.h"

/**
 * Accepted 2023-01-29
 * 105/105 (132 ms)
 * Your runtime beats 9.37 % of cpp submissions
 * Your memory usage beats 8.86 % of cpp submissions (105 MB)
 */
// @lc code=start
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        size_t nums_size = nums.size();

        vector<int> sum_except_self(nums_size);

        int sum = 0;

        for (auto& num : nums) {
            sum += num;
        }

        for (size_t i = 0; i < nums_size; ++i) {
            sum_except_self.at(i) = sum - nums.at(i);
        }

        vector<int> dp_left(nums_size, 0);
        vector<int> dp_right(nums_size, 0);

        // 计算去除第i位后左边奇数的和

        /**
         * [6,1,7,4,1]
         *  0 0 1 1 5
         *  8 8 1 0 0
         */
        for (size_t i = 1; i < nums_size; ++i) {
            if (i % 2) {
                // 奇数下标
                dp_left[i] = dp_left[i - 1];
            } else {
                // 是非0偶数下标
                dp_left[i] = dp_left[i - 1] + nums[i - 1];
            }
        }

        // for (auto& n : dp_left) {
        //     cout << n << " ";
        // }
        // cout << endl;

        // 计算去除第i位后右边奇数的和
        for (int i = nums_size - 2; i > -1; --i) {
            if (i % 2) {
                // 奇数下标
                dp_right[i] = dp_right[i + 1] + nums[i + 1];
            } else {
                // 偶数下标
                dp_right[i] = dp_right[i + 1];
            }
        }

        // for (auto& n : dp_right) {
        //     cout << n << " ";
        // }
        // cout << endl;

        sum = 0;
        for (size_t i = 0; i < nums_size; ++i) {
            if (sum_except_self[i] == (dp_left[i] + dp_right[i]) * 2) {
                ++sum;
            }
        }

        return sum;
    }
};
// @lc code=end
