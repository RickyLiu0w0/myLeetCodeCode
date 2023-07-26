/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-25
 * 25/25 (4 ms)
 * Your runtime beats 33.12 % of cpp submissions
 * Your memory usage beats 29.62 % of cpp submissions (6.8 MB)
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const vector<pair<int,int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int length = matrix.at(0).size();
        int width = matrix.size();
        vector<int> res;
        pair<int, int> pos = {0, 0};
        int currentDirection = 0;
        while (1) {
            res.emplace_back(matrix[pos.first][pos.second]);
            matrix[pos.first][pos.second] = 102;

            // step
            pos.first += direction[currentDirection].first;
            pos.second += direction[currentDirection].second;
            function<bool(int,int)> peek = [&matrix, length, width](int x, int y) -> bool {
                return x < 0 || x == width || y < 0 || y == length || matrix[x][y] == 102;
            };

            if (peek(pos.first, pos.second)) {
                // 出界或碰到已遍历过的地方，退回来转向
                pos.first -= direction[currentDirection].first;
                pos.second -= direction[currentDirection].second;

                bool sucess = false;
                for (int i = 1; i < 4; ++i) {
                    pos.first += direction[(currentDirection + i) % 4].first;
                    pos.second += direction[(currentDirection + i) % 4].second;
                    if (!peek(pos.first, pos.second)) {
                        sucess = true;
                        currentDirection = (currentDirection + i) % 4;
                        break;
                    }
                }
                if (!sucess) {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

