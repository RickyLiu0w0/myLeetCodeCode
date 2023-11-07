/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-11-07
 * 61/61 (8 ms)
 * Your runtime beats 83.26 % of cpp submissions
 * Your memory usage beats 59.34 % of cpp submissions (9.8 MB)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.front().size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i && !j) {
                    grid[i][j] += grid[i - 1][j];
                } else if (j && !i) {
                    grid[i][j] += grid[i][j - 1];
                } else if (i && j) {
                    grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
                }
            }
        }
        return grid.back().back();
    }
};
// @lc code=end
