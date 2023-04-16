/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-04-15
 * 51/51 (112 ms)
 * Your runtime beats 62.75 % of cpp submissions
 * Your memory usage beats 41.29 % of cpp submissions (44.2 MB)
 */
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> res(n, 0);
        vector<vector<int>> path_graph(n);
        // 绘制邻接矩阵
        for (auto& path : paths) {
            path_graph[path[0] - 1].emplace_back(path[1] - 1);
            path_graph[path[1] - 1].emplace_back(path[0] - 1);
        }

        function<bool(int)> dfs = [&](int garden) -> bool {
            // base case
            if (garden == n) {
                return true;
            }

            // 选择列表
            for (int flower = 1; flower < 5; ++flower) {
                bool flag = false;
                for (auto& gard : path_graph[garden]) {
                    if (res[gard] == flower) {
                        flag = true;  // 该花无效
                        break;
                    }
                }

                if (flag) {
                    continue;
                }

                // 该花有效
                res[garden] = flower;
                if (dfs(garden + 1)) {
                    return true;  // 找到可行方案
                } else {
                    // 撤销选择
                    res[garden] = 0;
                }
            }
            return false;
        };
        dfs(0);
        return res;
    }
};
// @lc code=end
