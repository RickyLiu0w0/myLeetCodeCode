/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-07
 * 180/180 (12 ms)
 * Your runtime beats 60.25 % of cpp submissions
 * Your memory usage beats 28.03 % of cpp submissions (11.3 MB)
*/
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> ma;
        for (auto num : nums) {
            ma[num]++;
        }
        sort(nums.begin(), nums.end(), [&ma](const int& a, const int& b)->bool{
            if (ma[a] == ma[b]) {
                return a > b;
            }
            return ma[a] < ma[b];
        });
        return nums;
    }
};
// @lc code=end

