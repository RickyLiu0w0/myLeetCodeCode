/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
 */

#include "AllInclude.h"

/**
 * Accepted 2023-03-01
 * 50/50 (16 ms)
 * Your runtime beats 54.26 % of cpp submissions
 * Your memory usage beats 5.43 % of cpp submissions (11.8 MB)
*/

// @lc code=start
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        size_t n = grid.size();
        vector<vector<int>> res;
        for (size_t i = 1; i < n - 1; ++i) {
            vector<int> row;
            for (size_t j = 1; j < n - 1; ++j) {
                row.emplace_back(
                    std::max(std::max(*max_element(grid.at(i - 1).begin() + (j - 1), grid.at(i - 1).begin() + (j + 2)),
                                      *max_element(grid.at(i).begin() + (j - 1), grid.at(i).begin() + (j + 2))),
                             *max_element(grid.at(i + 1).begin() + (j - 1), grid.at(i + 1).begin() + (j + 2))));
            }
            res.emplace_back(row);
        }

        return res;
    }
};
// @lc code=end

/*
[[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]\n
[[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
*/