/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

#include "AllInclude.h"

// @lc code=start
// 刚好可以练练图，暴力解法
/**
 * Accepted 2023-03-15
 * 82/82 (92 ms)
 * Your runtime beats 22.91 % of cpp submissions
 * Your memory usage beats 76.82 % of cpp submissions (27.6 MB)
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<uint32_t> degree(n, 0);                                  // 统计度
        vector<vector<bool>> connect_table(n, vector<bool>(n, false));  // 邻接表

        for (auto& road : roads) {
            ++degree[road[0]];
            ++degree[road[1]];
            connect_table[road[0]][road[1]] = true;
            connect_table[road[1]][road[0]] = true;
        }

        // 暴力遍历所有节点
        uint32_t res = 0;
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                res = std::max(res, degree[i] + degree[j] - connect_table[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end
