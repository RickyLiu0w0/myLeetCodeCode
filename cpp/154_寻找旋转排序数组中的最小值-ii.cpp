/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-15
 * 193/193 (4 ms)
 * Your runtime beats 85.25 % of cpp submissions
 * Your memory usage beats 19.45 % of cpp submissions (12 MB)
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        auto is_blue = [&nums](int mid) -> bool {
            if (nums[mid] < nums.back()) {
                return true;
            } else if (nums[mid] > nums.back()) {
                return false;
            }

            // nums[mid] == nums.back()
            if (nums.back() != nums.front()) {
                return true;
            }

            while (mid && nums[mid - 1] == nums[mid]) {
                --mid;
            }
            return mid;
        };

        int left = -1, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + ((right - left ) >> 1);
            if (is_blue(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right];
    }
};
// @lc code=end

/*
[1,1,2,3,3,0,0,1,1]\n
[1,3,5]\n
[3,3,1]\n
[2,2,2,0,1]\n
[3,3,1,3]\n
[1,3,3]
*/