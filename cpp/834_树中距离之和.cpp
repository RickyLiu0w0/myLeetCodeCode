/*
 * @lc app=leetcode.cn id=834 lang=cpp
 *
 * [834] 树中距离之和
 */

#include "AllInclude.h"

// @lc code=start
/**
 * Accepted 2023-07-18
 * 74/74 (296 ms)
 * Your runtime beats 25.71 % of cpp submissions
 * Your memory usage beats 37.86 % of cpp submissions (102.5 MB)
 */
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // 建树
        vector<vector<int>> g(n); // 树，邻接矩阵
        for (vector<int>& edge : edges) {
            int x = edge.at(0);
            int y = edge.at(1);
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> subTreeSize(n, 1); // 自己也是子树的一种
        vector<int> res(n, 0); // 结果

        // 先直接用dfs计算从0出发到所有节点的距离
        int path_size = 0;
        function<void(int, int)> dfs = [&](int node, int parent) {
            for (int child : g[node]) {
                if (child != parent) {
                    // 选择
                    path_size++;
                    dfs(child, node);
                    // 撤销选择
                    path_size--;
                    subTreeSize[node] += subTreeSize[child];
                }
            }
            res[0] += path_size;
        };

        dfs(0, -1);

        function<void(int, int)> changeRoot = [&](int node, int parent) {
            for (int child : g[node]) {
                if (child != parent) {
                    // 若x是y的父节点，res[y]对于res[x]来说，如果点在y的子树中（subTreeSize[y]），则距离比res[x]-1，
                    // 如果不在y的子树中（n - subTreeSize[y]），则距离比res[x]+1
                    // 所以 res[y] = res[x] - 1 * subTreeSize[y] + 1 * (n - subTreeSize[y])
                    // res[y] = res[x] + n - 2 * subTreeSize[y];
                    res[child] = res[node] + n - 2 * subTreeSize[child];
                    changeRoot(child, node);
                }
            }
        };

        changeRoot(0, -1);

        return res;
    }
};
// @lc code=end

/*
6\n[[0,1],[0,2],[2,3],[2,4],[2,5]]\n
1\n[]\n
2\n[[1,0]]
*/