/*
 * @lc app=leetcode.cn id=2605 lang=cpp
 *
 * [2605] 从两个数字数组里生成最小数字
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-05
 * 388/388 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 35.23 % of cpp submissions (21.3 MB)
*/
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // 判断有没有个数
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ++i;
            } else if (nums2[j] < nums1[i]) {
                ++j;
            } else {
                return nums1[i];
            }
            
        }
        return min(nums1.front()*10 + nums2.front(), nums2.front()*10 + nums1.front());
    }
};
// @lc code=end

/*
[4,1,3]\n[5,7]\n
[3,5,2,6]\n[3,1,7]\n
[6]\n[3]\n
[1,2,3,4,5]\n[5,6,7,8,9]\n
[1,2,3,4,5]\n[4,5,6,7,8,9]\n
[1,2,3,4,5]\n[6,7,8,9]\n
*/