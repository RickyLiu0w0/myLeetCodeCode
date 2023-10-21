/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-10-21
 * 66/66 (540 ms)
 * Your runtime beats 42.62 % of cpp submissions
 * Your memory usage beats 24.6 % of cpp submissions (195.8 MB)
 */
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> grid(n, vector<int>()); // 邻接表
        for (auto & edge : edges) {
            int x = edge.front(), y = edge.back();
            grid[x].emplace_back(y);
            grid[y].emplace_back(x);
        }
        
        vector<bool> visted(n, false);
        function<int(int)> dfs = [&](int node) -> int {
            visted[node] = true;
            int size = 1;
            for (auto nxt : grid[node]) {
                if (!visted[nxt]) {
                    size += dfs(nxt);
                }
            }
            return size;
        };

        long long res = 0, total = 0;
        for (int i = 0; i < n; ++i) {
            if (!visted[i]) {
                int cnt = dfs(i);
                res += total * cnt;
                total += cnt;
            }
        }
        return res;
    }
};
// @lc code=end

