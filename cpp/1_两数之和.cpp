/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include "AllInclude.h"

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numsV;
        int numsSize = nums.size();
        for(int i = 0; i < numsSize; ++i) {
            numsV.push_back(make_pair(i, nums[i]));
        }

        sort(numsV.begin(), numsV.end(),
            [](pair<int, int>& a, pair<int, int>& b) -> bool {
                return a.second < b.second;
            }
        );

        int minPtr = 0, maxPtr = numsSize - 1;
        int sum  = numsV[0].second + numsV[maxPtr].second;
        while (target != sum) {
            if (target > sum) ++minPtr;
            else --maxPtr;
            sum = numsV[minPtr].second + numsV[maxPtr].second;
        }
        return vector<int>{numsV[minPtr].first, numsV[maxPtr].first};
    }
};
// @lc code=end

/*
[2,7,11,15]\n
9\n
[3,2,4]\n
6\n
[3,3]\n
6\n
[2,8,3,4,5,2]\n
12\n
*/