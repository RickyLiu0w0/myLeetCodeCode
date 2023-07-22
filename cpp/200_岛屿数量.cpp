/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-19
 * 49/49 (28 ms)
 * Your runtime beats 90.6 % of cpp submissions
 * Your memory usage beats 83.21 % of cpp submissions (11.9 MB)
 */
class Solution {
public:
    // 这道题是最基础的DFS遍历，通过0标记为已遍历过 
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int length = grid.at(0).size();
        int width = grid.size();
        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x == width || y < 0 || y == length) {
                return;
            }

            if (grid[x][y] == '0') {
                return;
            }

            grid[x][y] = '0'; // 标记为被水淹没
            // 四个方向处理
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        };

        for (int i = 0; i < width; ++i) {
            for (size_t j = 0; j < length; ++j) {
                if (grid[i][j] == '1') {
                    // 淹没掉，统计数+1
                    ++res;
                    dfs(i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
[["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
*/