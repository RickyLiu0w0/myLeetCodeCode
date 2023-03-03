/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-03-03
 * 312/312 (364 ms)
 * Your runtime beats 7 % of cpp submissions
 * Your memory usage beats 6.33 % of cpp submissions (31.4 MB)
 * */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        vector<vector<int>> res;
        for (size_t i = 0; i < n - 1;) {
            int num = nums.at(i);
            size_t l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int left = nums.at(l), right = nums.at(r);
                int sum = left + right;
                if (sum < -num) {
                    // 往右移动
                    while (l < r && nums.at(l) == left) ++l;
                } else if (sum > -num) {
                    // 往左移动
                    while (l < r && nums.at(r) == right) --r;
                } else {
                    // 相等
                    res.emplace_back(vector<int>{num, left, right});
                    while (l < r && nums.at(l) == left) ++l;
                    while (l < r && nums.at(r) == right) --r;
                }
            }
            while (i < n && nums.at(i) == num) ++i;
        }
        return res;
    }
};
// @lc code=end
