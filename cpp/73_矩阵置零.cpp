/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-09-18
 * 175/175 (16 ms)
 * Your runtime beats 41.77 % of cpp submissions
 * Your memory usage beats 5.09 % of cpp submissions (13.6 MB)
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<pair<int, int>> v;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    // 记录0的位置
                    v.emplace_back(make_pair(i, j));
                }
            }
        }

        for (auto &[a, b] : v) {
            make_zero(matrix, a, b, 0, 1);
            make_zero(matrix, a, b, 0, -1);
            make_zero(matrix, a, b, 1, 0);
            make_zero(matrix, a, b, -1, 0);
        }

        return;
    }
private:
    int m, n;
    void make_zero(vector<vector<int>>& matrix, int x, int y, int step_x, int step_y) {
        do {
            matrix[x][y] = 0;
            x += step_x;
            y += step_y;
        } while (x > - 1 && x < m && y > -1 && y < n);
    }
};
// @lc code=end

