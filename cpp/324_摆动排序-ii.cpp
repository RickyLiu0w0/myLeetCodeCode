/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */
#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int numSize = nums.size();
        if (numSize == 1)
            return;
        sort(nums.begin(), nums.end());
        int mid = numSize / 2;
        if (numSize % 2) {
            mid = nums[mid + 1] == nums[mid] ? mid : mid - 1;
        } else {
            mid = mid - 1;
        }
        int maxPtr = numSize - 1;
        int minPtr = mid;

        vector<int> temp;
        while (minPtr > -1 && maxPtr > mid) {
            temp.push_back(nums[minPtr--]);
            temp.push_back(nums[maxPtr--]);
        }

        if (minPtr == 0) {
            temp.push_back(nums[0]);
        }

        if (maxPtr == mid + 1) {
            temp.push_back(nums[mid + 1]);
        }

        nums.assign(temp.begin(), temp.end());
        return;
    }
};
// @lc code=end

/*
[1,5,1,1,6,4]\n
[1,1,1,1,1,2,6,4,5,3]\n
[1,3,2,2,3,1]\n
[2,1]\n
[1,1,2,1,2,2,1]\n
[1,4,3,4,1,2,1,3,1,3,2,3,3]\n
[5,3,1,2,6,7,8,5,5]
*/