/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-08-19
 * 22/22 (4 ms)
 * Your runtime beats 39.38 % of cpp submissions
 * Your memory usage beats 5.46 % of cpp submissions (7.2 MB)
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> board_old = board;
        const int x_step[3] = {-1, 0, 1};
        const int y_step[3] = {-1, 0, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live = 0;
                for (int ii = 0; ii < 3; ++ii) {
                    for (int jj = 0; jj < 3; ++jj) {
                        if (x_step[ii] || y_step[jj]) {
                            int x = i + x_step[ii];
                            int y = j + y_step[jj];
                            if (x > -1 && x < m && y > -1 && y < n) {
                                if (board_old[x][y]) {
                                    live++;
                                }
                            }
                        }
                    }
                }
                if (board_old[i][j]) {
                    if (live < 2 || live > 3) {
                        board[i][j] = 0;
                    }
                } else {
                    if (live == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};
// @lc code=end

