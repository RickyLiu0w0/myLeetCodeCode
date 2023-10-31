/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-02
 * 113/113 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 22.36 % of cpp submissions (8.6 MB)
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 双指针
        int fast = 0, slow = 0, n = nums.size();
        while (fast < n) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return slow;
    }
};
// @lc code=end

/*
[3,2,2,3]\n3\n
[0,1,2,2,3,0,4,2]\n2\n
[3,2,3,3]\n3\n
[3,3,3,3]\n3\n
[3,3,3,2]\n3\n
[]\n1\n
[1,2,3]\n5
*/