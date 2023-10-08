/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-08
 * 1027/1027 (12 ms)
 * Your runtime beats 85.52 % of cpp submissions
 * Your memory usage beats 51.13 % of cpp submissions (27.6 MB)
 */
const int DIRECTION[16] = {-1, -2, -2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2};

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int x = 0, y = 0, step = 1, n = grid.size();
        if (grid[0][0]) {
            return false;
        }
        while (step < n * n) {
            int i = 0;
            for (; i < 16; i += 2) {
                int nxt_x = x + DIRECTION[i];
                int nxt_y = y + DIRECTION[i + 1];
                if (nxt_x > -1 && nxt_x < n && nxt_y > -1 && nxt_y < n) {
                    if (grid[nxt_x][nxt_y] == step) {
                        ++step;
                        x = nxt_x;
                        y = nxt_y;
                        break;
                    }
                }
            }
            if (i == 16) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

/*

[[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]\n
[[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]\n
[[0,3,6],[5,8,1],[2,7,4]]
*/
