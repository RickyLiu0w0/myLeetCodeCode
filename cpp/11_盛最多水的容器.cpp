/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-27
 * 61/61 (72 ms)
 * Your runtime beats 68.03 % of cpp submissions
 * Your memory usage beats 10.97 % of cpp submissions (57.7 MB)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 双指针
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                // 左边矮
                res = max(res, height[l] * (r - l));
                l++;
            } else {
                res = max(res, height[r] * (r - l));
                r--;
            }
        }
        return res;
    }
};
// @lc code=end

/*
[1,8,6,2,5,4,8,3,7]\n
[1,1]
*/
