/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

#include "AllInclude.h"

/**
 * Accepted 2022-11-16
 * 226/226 (136 ms)
 * Your runtime beats 20.25 % of cpp submissions
 * Your memory usage beats 21.47 % of cpp submissions (81.4 MB)
*/

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        size_t size = nums.size();
        if (size < 3) return true;
        int max_num = 0;
        for (size_t i = 0; i < size - 2; ++i) {
            max_num = max(max_num, nums[i]);
            if (max_num > nums[i + 2]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
/*
[0]\n
[1,0]\n
[0,1,2]\n
[1,2,3,0]\n[1,2,0,3]\n[1,3,2,0]\n[1,3,0,2]\n[1,0,2,3]\n[1,0,3,2]\n[2,1,3,0]\n[2,1,0,3]\n[2,3,1,0]\n[2,3,0,1]\n[2,0,1,3]\n[2,0,3,1]\n[3,1,2,0]\n[3,1,0,2]\n[3,2,1,0]\n[3,2,0,1]\n[3,0,1,2]\n[3,0,2,1]\n[0,1,2,3]\n[0,1,3,2]\n[0,2,1,3]\n[0,2,3,1]\n[0,3,1,2]\n[0,3,2,1]
*/
