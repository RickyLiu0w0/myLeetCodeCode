/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-29
 * 25/25 (0 ms)
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 12.62 % of cpp submissions (6.8 MB)
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        m = matrix.size();
        n = matrix.front().size();
        int i = 0, j = 0;
        int cnt = m * n;
        direction = right;
        while (cnt) {
            res.emplace_back(matrix[i][j]);
            matrix[i][j] = 101;
            next_num(matrix, i, j);
            cnt--;
        }
        return res;
    }

private:
    enum Direction { up, down, left, right } direction;
    int m, n;

    void next_num(vector<vector<int>>& matrix, int& i, int& j) {
        switch (direction) {
            case up:
                if (m == 0 || matrix[i - 1][j] == 101) {
                    // 无法往上，只能往右
                    j++;
                    direction = right;
                } else {
                    i--;
                }
                break;

            case down: 
                if (i + 1 == m || matrix[i + 1][j] == 101) {
                    // 无法往下，只能往左
                    j--;
                    direction = left;
                } else {
                    i++;
                }
                break;

            case right:
                if (j + 1 == n || matrix[i][j + 1] == 101){
                    // 无法往右，只能往下
                    i++;
                    direction = down;
                } else {
                    j++;
                }
                break;

            default:
                if (j == 0 || matrix[i][j - 1] == 101) {
                    //  无法往左，只能往上
                    --i;
                    direction = up;
                } else {
                    --j;
                }
                break;
        }
        return;
    }
};
// @lc code=end
