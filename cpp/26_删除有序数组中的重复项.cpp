/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-02
 * 361/361 (4 ms)
 * Your runtime beats 97.88 % of cpp submissions
 * Your memory usage beats 16.27 % of cpp submissions (18 MB)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), slow = 0, fast = 0;
        while (fast < n) {
            if (nums[slow] != nums[fast]) {
                nums[++slow] = nums[fast];
            }
            ++fast;
        }
        return slow + 1;
    }
};
// @lc code=end

/*
[1,1,2]\n
[0,0,1,1,1,2,2,3,3,4]\n
[1,1,1]\n
[0]\n
[5,6,7,7,8,8,8,9,10,10,10,10]
*/