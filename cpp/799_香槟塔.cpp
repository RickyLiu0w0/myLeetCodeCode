/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2022-11-20
 * 312/312 (16 ms)
 * Your runtime beats 34.5 % of cpp submissions
 * Your memory usage beats 39.61 % of cpp submissions (14.2 MB)
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0.0));
        dp.at(1).at(1) = poured;
        for (int r = 2; r < query_row + 2; ++r) {
            for (int g = 1; g < r + 1; ++g) {
                dp.at(r).at(g) = max(0.0, dp.at(r - 1).at(g - 1) - 1) / 2 + max(0.0, dp.at(r - 1).at(g) - 1) / 2;
            }
        }
        return min(dp.at(query_row + 1).at(query_glass + 1), 1.0);
    }
};
// @lc code=end
