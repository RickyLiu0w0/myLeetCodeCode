/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-08
 * 58/58 (16 ms)
 * Your runtime beats 34.02 % of cpp submissions
 * Your memory usage beats 27.39 % of cpp submissions (10 MB)
 */
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board.front().size();
        const array<array<int, 2>, 4> direction = {0,-1, 0, 1, -1, 0, 1,0};
        function<void(int, int)> dfs = [&](int row, int col) {
            if (row == -1 || col == -1 || row == m || col == n || 'O' != board[row][col]) {
                // 结束条件
                return;
            }

            // 作出处理
            board[row][col] = '%'; // 特殊标记
            
            // 选择列表
            for (int i = 0; i < 4; ++i){
                // 遍历上下左右四个方向
                dfs(row + direction[i][0], col + direction[i][1]);
            }
            return;
        };

        // 将与边边相连的O都更改标记为%
        for (int j = 0; j < n; ++j) {
            // 第一行以及最后一行
            dfs(0, j);
            dfs(m - 1, j);
        }

        for (int i = 1; i < m - 1; ++i) {
            // 第一列以及最后一列，排除第一行以及最后一行，因为已经处理了
            dfs(i, 0);
            dfs(i, n - 1);
        }

        // 将中间内部的O转变为X，%转为O
        for (auto& r : board) {
            for (auto& item : r) {
                if (item == 'O') {
                    item = 'X';
                } else if (item == '%') {
                    item = 'O';
                }
            }
        }
        return;
    }
};
// @lc code=end

