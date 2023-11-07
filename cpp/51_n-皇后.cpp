/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-31
 * 9/9 (4 ms)
 * Your runtime beats 94.71 % of cpp submissions
 * Your memory usage beats 61.94 % of cpp submissions (7.4 MB)
 */
class Solution {
public:
    // 标准回溯
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> grid(n, string(n, '.'));
        auto canPut = [&grid, n](int i, int j) -> bool {
            // 往上看
            for (int k = i - 1; k > -1 ; --k) {
                if (grid[k][j] == 'Q') {
                    return false;
                }
            }
            // 往左上
            for (int k = i, K = j; k > -1 && K > -1; --k, --K) {
                if (grid[k][K] == 'Q') {
                    return false;
                }
            }
            // 往右上
            for (; i > -1 && j < n; --i, ++j) {
                if (grid[i][j] == 'Q') {
                    return false;
                }
            }
            return true;
        };

        function<void(int)> backTrack = [&](int i) {
            if (i == n) {
                res.emplace_back(grid);
                return;
            }

            for (int j = 0; j < n; ++j) {
                if (canPut(i, j)) {
                    grid[i][j] = 'Q';
                    backTrack(i + 1);
                    grid[i][j] = '.';
                }
            }
        };
        backTrack(0);
        return res;
    }
};
// @lc code=end

