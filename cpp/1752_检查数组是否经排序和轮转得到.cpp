/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-11-28
 * 105/105 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 16.9 % of cpp submissions (8.4 MB)
 */
class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size(), counter = 0;
        nums.insert(nums.end(), nums.begin(), nums.end());
        bool flag = true;

        for (size_t i = 1; i < size * 2; ++i) {
            if (nums[i - 1] > nums[i]) {
                if (flag) {
                    flag = false;
                } else {
                    return false;
                }
            }

            if (++counter == size) {
                return true;
            }
        }

        return true;
    }
};
// @lc code=end
/*
[6,10,6]\n
[1,1,1]\n
[7,9,1,1,1,3]\n
[1,2,3]\n
[2,1]
*/