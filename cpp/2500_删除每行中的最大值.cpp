/*
 * @lc app=leetcode.cn id=2500 lang=cpp
 *
 * [2500] 删除每行中的最大值
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-25
 * 55/55 (20 ms)
 * Your runtime beats 23.68 % of cpp submissions
 * Your memory usage beats 37.22 % of cpp submissions (9.2 MB)
 */
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.at(0).size();
        int res = 0;
        for (auto& row : grid) {
            sort(row.begin(), row.end(), less<int>());
        }
        for (int j = 0; j < n; j++) {
            int m = INT_MIN;
            for (auto& row : grid) {
                m = max(m, row[j]);
            }
            res += m;
        }
        return res;
    }
};
// @lc code=end

